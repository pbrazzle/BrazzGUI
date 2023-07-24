#ifndef WINDOW
#define WINDOW

#include "LayoutController.hpp"
#include "Menu.hpp"
#include "MenuItem.hpp"
#include "ParentControl.hpp"

#include <memory>


namespace BrazzGUI {
/**
 * Windows are top-level ParentControls
 * They can also have Menus
 */
class Window : public ParentControl<ControlType::Window> {
    private:
    Menu menu;

    public:
    Window();

    void addMenuItem(const MenuItem& item);
};

} // namespace BrazzGUI

#endif