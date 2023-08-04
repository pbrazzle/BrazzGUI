#pragma once

#include "Handlers/MenuHandler.hpp"
#include "MenuItem.hpp"

#include <map>
#include <vector>
#include <windows.h>

namespace BrazzGUI::Handlers::Win32 {
/**
 * MenuHandler with Win32 specific data
 */
class Win32MenuHandler : public MenuHandler {
    private:
    HMENU handle;
    HWND parentHandle;
    std::vector<const MenuItem*> subItems;
    Win32MenuHandler* parentMenu;
    ControlID id;

    void setParent(Win32MenuHandler*);

    static std::map<HMENU, ControlID> idMap;
    static std::map<ControlID, HMENU> parentMap;

    ControlID getChild(int index);

    public:
    Win32MenuHandler(const MenuType, ControlID);

    /***
     * Adds a subitem to this MenuHandler
     *
     * @param item MenuItem to be added
     */
    void addItem(const MenuItem& item);

    /**
     * Sets this Menu as the Windows top Menu
     *
     * @param parent Window to display this Menu
     */
    void registerMenu(const Window& parent);

    static ControlID getIDFromHandle(const HMENU h);
    static ControlID getChildIDFromHandle(const HMENU h, int index);

    void setText(const std::string& text);
};
} // namespace BrazzGUI::Handlers::Win32