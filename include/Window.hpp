#ifndef WINDOW
#define WINDOW

#include "LayoutController.hpp"
#include "ParentControl.hpp"

namespace BrazzGUI {
/**
 * Windows are top-level ParentControls
 * They can also have Menus
 */
class Window : public ParentControl {
    public:
    /**
     * Creates a new Window
     */
    Window();
};
} // namespace BrazzGUI

#endif