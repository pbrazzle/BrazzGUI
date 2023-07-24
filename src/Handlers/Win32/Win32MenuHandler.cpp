#include "Handlers/Win32/Win32MenuHandler.hpp"

#include "ControlHandling/Win32/ControlHandling.hpp"
#include "Window.hpp"

#include <windows.h>

using namespace BrazzGUI::Handlers::Win32;

Win32MenuHandler::Win32MenuHandler(const MenuType type) :
    MenuHandler(type),
    parentHandle(NULL) {
    switch (type) {
        case MenuType::MenuBar:
            handle = CreateMenu();
            break;
        case MenuType::MenuItem:
            handle = CreatePopupMenu();
            break;
    }
}

void Win32MenuHandler::addItem(const MenuItem& item) {
    // TEST - Add a 'test' menu item

    MENUITEMINFO info = {0};
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_STRING;
    info.fType = MFT_STRING;
    info.dwTypeData = "test";
    info.cch = 4;

    InsertMenuItem(handle, 0, TRUE, &info);

    if (parentHandle != NULL) DrawMenuBar(parentHandle);
}

void Win32MenuHandler::registerMenu(const Window& parent) {
    parentHandle = ControlHandling::getHandleFromID(parent.getID());
    SetMenu(parentHandle, handle);
}

std::unique_ptr<BrazzGUI::Handlers::MenuHandler>
BrazzGUI::Handlers::createMenuHandler(BrazzGUI::Handlers::MenuType type) {
    return std::make_unique<Win32MenuHandler>(type);
}