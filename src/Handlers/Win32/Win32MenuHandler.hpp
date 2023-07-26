#pragma once

#include "Handlers/MenuHandler.hpp"
#include "MenuItem.hpp"

#include <map>
#include <vector>
#include <windows.h>

namespace BrazzGUI::Handlers::Win32 {
/**
 * TODO document this class
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
     * TODO document this function
     */
    void addItem(const MenuItem& item);

    /**
     * TODO document this function
     */
    void registerMenu(const Window& parent);

    static ControlID getIDFromHandle(const HMENU h);
    static ControlID getChildIDFromHandle(const HMENU h, int index);

    void setText(const std::string& text);
};
} // namespace BrazzGUI::Handlers::Win32