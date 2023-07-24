#include "Handlers/Win32/Win32MenuHandler.hpp"

#include "ControlHandling/Win32/ControlHandling.hpp"
#include "MenuItem.hpp"
#include "Window.hpp"

using namespace BrazzGUI;

void Handlers::Win32::Win32MenuHandler::addTopLevelItem(const Window& window,
                                                        const MenuItem& item) {
    // Check if Window has a Menu
    auto parentHandle = ControlHandling::getHandleFromID(window.getID());

    auto menu = GetMenu(parentHandle);

    // Create a Menu for the Window if it has none
    if (menu == NULL) {
        menu = CreateMenu();
        SetMenu(parentHandle, menu);
    }

    int numItems = GetMenuItemCount(menu);

    MENUITEMINFO menuItemInfo = {0};
    menuItemInfo.cbSize = sizeof(MENUITEMINFO);
    menuItemInfo.fMask = MIIM_STRING;
    menuItemInfo.fType = MFT_STRING;
    menuItemInfo.fState = MFS_ENABLED;
    menuItemInfo.dwTypeData = reinterpret_cast<LPTSTR>("test");
    menuItemInfo.cch = 4;
    InsertMenuItem(menu, numItems, TRUE, &menuItemInfo);
}

void Handlers::Win32::Win32MenuHandler::addSubItem(const MenuItem& parent,
                                                   const MenuItem& child) {}

std::unique_ptr<Handlers::MenuHandler> Handlers::getDefaultMenuHandler() {
    return std::make_unique<Handlers::Win32::Win32MenuHandler>();
}