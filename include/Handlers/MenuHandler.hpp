#pragma once

namespace BrazzGUI {
class MenuItem;
class Window;
} // namespace BrazzGUI

#include "ControlID.hpp"

#include <memory>
#include <string>

namespace BrazzGUI::Handlers {

enum class MenuType { MenuBar, MenuItem };

class MenuHandler {
    private:
    MenuHandler();

    public:
    MenuHandler(const MenuType) {}

    virtual ~MenuHandler() {}

    /***
     * Adds a subitem to this MenuHandler
     * If this is the first child item, turns this MenuHandler into a parent
     * Menu
     */
    virtual void addItem(const MenuItem& item) = 0;

    virtual void registerMenu(const Window& parent) = 0;

    virtual void setText(const std::string& text) = 0;
};

std::unique_ptr<MenuHandler> createMenuHandler(MenuType, ControlID);
} // namespace BrazzGUI::Handlers