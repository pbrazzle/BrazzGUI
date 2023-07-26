#include "Handlers/Win32/Win32MenuHandler.hpp"

#include "ControlHandling/Win32/ControlHandling.hpp"
#include "Window.hpp"

#include <algorithm>
#include <windows.h>

using namespace BrazzGUI::Handlers::Win32;

std::map<HMENU, BrazzGUI::ControlID> Win32MenuHandler::idMap;
std::map<BrazzGUI::ControlID, HMENU> Win32MenuHandler::parentMap;

Win32MenuHandler::Win32MenuHandler(const MenuType type, ControlID id) :
    MenuHandler(type),
    id(id),
    parentHandle(NULL) {
    switch (type) {
        case MenuType::MenuBar: {
            handle = CreateMenu();
            MENUINFO menuInfo = {0};
            menuInfo.cbSize = sizeof(MENUINFO);
            menuInfo.fMask = MIM_STYLE;
            menuInfo.dwStyle = MNS_NOTIFYBYPOS;
            SetMenuInfo(handle, &menuInfo);
            break;
        }
        case MenuType::MenuItem:
            handle = NULL;
            break;
    }
}

void Win32MenuHandler::setParent(Win32MenuHandler* p) { parentMenu = p; }

HMENU findHandleFromID(std::map<HMENU, BrazzGUI::ControlID>& map,
                       BrazzGUI::ControlID id) {
    auto found = std::find_if(map.begin(), map.end(), [&](auto item) {
        return item.second.getValue() == id.getValue();
    });
    if (found == map.end()) return NULL;
    return (*found).first;
}

int findIndexByHandler(HMENU menu, const Win32MenuHandler* handler) {
    for (int i = 0; i < GetMenuItemCount(menu); i++) {
        MENUITEMINFO info = {0};
        info.cbSize = sizeof(MENUITEMINFO);
        info.fMask = MIIM_DATA;

        GetMenuItemInfo(menu, i, TRUE, &info);

        if (reinterpret_cast<Win32MenuHandler*>(info.dwItemData) == handler)
            return i;
    }
    return -1;
}

void Win32MenuHandler::addItem(const MenuItem& item) {
    if (subItems.size() == 0 && handle == NULL) {
        handle = CreatePopupMenu();

        // Set up WM_MENUCOMMAND
        MENUINFO menuInfo = {0};
        menuInfo.cbSize = sizeof(MENUINFO);
        menuInfo.fMask = MIM_STYLE;
        menuInfo.dwStyle = MNS_NOTIFYBYPOS;
        SetMenuInfo(handle, &menuInfo);

        idMap[handle] = id;
        if (parentMap.count(id)) {
            int index = findIndexByHandler(parentMap[id], this);

            MENUITEMINFO newInfo = {0};
            newInfo.cbSize = sizeof(MENUITEMINFO);
            newInfo.fMask = MIIM_SUBMENU;
            newInfo.hSubMenu = handle;

            SetMenuItemInfo(parentMap[id], index, TRUE, &newInfo);
        }
    }
    subItems.push_back(&item);

    parentMap[item.getID()] = handle;
    // TEST - Add a 'test' menu item
    MENUITEMINFO info = {0};
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_STRING | MIIM_DATA;
    auto subItemHandle = findHandleFromID(idMap, item.getID());
    if (subItemHandle != NULL) {
        info.fMask |= MIIM_SUBMENU;
        info.hSubMenu = subItemHandle;
    }
    auto itemText = item.getText();
    char* buf = new char[itemText.size() + 1];
    buf[itemText.size()] = '\0';
    itemText.copy(buf, itemText.size());
    info.dwTypeData = buf;
    info.dwItemData = reinterpret_cast<ULONG_PTR>(this);

    InsertMenuItem(handle, 0, TRUE, &info);
    delete[] buf;

    if (parentHandle != NULL) DrawMenuBar(parentHandle);
}

void Win32MenuHandler::registerMenu(const Window& parent) {
    parentHandle = ControlHandling::getHandleFromID(parent.getID());
    SetMenu(parentHandle, handle);
}

std::unique_ptr<BrazzGUI::Handlers::MenuHandler>
BrazzGUI::Handlers::createMenuHandler(BrazzGUI::Handlers::MenuType type,
                                      ControlID id) {
    return std::make_unique<Win32MenuHandler>(type, id);
}

BrazzGUI::ControlID Win32MenuHandler::getIDFromHandle(const HMENU h) {
    return idMap.at(h);
}

void Win32MenuHandler::setText(const std::string& text) {
    // Get parent handle and index
    auto parentHandle = parentMap[id];
    int index = findIndexByHandler(parentHandle, this);
    MENUITEMINFO info = {0};
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_STRING;
    info.cch = text.size();
    char* buf = new char[text.size() + 1];
    buf[text.size()] = '\0';
    text.copy(buf, text.size());
    info.dwTypeData = buf;

    SetMenuItemInfo(handle, index, TRUE, &info);
    delete[] buf;
}

BrazzGUI::ControlID Win32MenuHandler::getChildIDFromHandle(const HMENU h,
                                                           int index) {
    if (index < 0 || index > GetMenuItemCount(h) || GetMenuItemCount(h) == 0)
        return ControlID(-1);
    MENUITEMINFO info = {0};
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_DATA;

    GetMenuItemInfo(h, index, TRUE, &info);
    auto handler = reinterpret_cast<Win32MenuHandler*>(info.dwItemData);
    return handler->getChild(index);
}

BrazzGUI::ControlID Win32MenuHandler::getChild(int index) {
    return subItems[index]->getID();
}