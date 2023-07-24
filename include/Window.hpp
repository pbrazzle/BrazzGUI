#ifndef WINDOW
#define WINDOW

#include "Handlers/MenuHandler.hpp"
#include "LayoutController.hpp"
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
    std::unique_ptr<Handlers::MenuHandler> menuHandler;

    public:
    Window();
    Window(std::unique_ptr<Handlers::MenuHandler> mHandler);

    void addMenuItem(const MenuItem& item);
};

} // namespace BrazzGUI

#endif