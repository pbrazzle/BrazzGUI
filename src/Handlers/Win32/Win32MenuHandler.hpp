#pragma once

#include "Handlers/MenuHandler.hpp"
#include "MenuItem.hpp"

#include <windows.h>

namespace BrazzGUI::Handlers::Win32 {
/**
 * TODO document this class
 */
class Win32MenuHandler : public MenuHandler {
    private:
    HMENU handle;
    HWND parentHandle;

    public:
    Win32MenuHandler(const MenuType);

    /***
     * TODO document this function
     */
    void addItem(const MenuItem& item);

    void registerMenu(const Window& parent);
};
} // namespace BrazzGUI::Handlers::Win32