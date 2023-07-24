#pragma once

namespace BrazzGUI {
class MenuItem;
class Window;
} // namespace BrazzGUI

#include <memory>

namespace BrazzGUI::Handlers {

enum class MenuType { MenuBar, MenuItem };

class MenuHandler {
    private:
    MenuHandler();

    public:
    MenuHandler(const MenuType) {}

    virtual ~MenuHandler() {}

    /***
     * TODO document this function
     */
    virtual void addItem(const MenuItem& item) = 0;

    virtual void registerMenu(const Window& parent) = 0;
};

std::unique_ptr<MenuHandler> createMenuHandler(MenuType);
} // namespace BrazzGUI::Handlers