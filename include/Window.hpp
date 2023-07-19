#ifndef WINDOW
#define WINDOW

#include "LayoutController.hpp"
#include "ParentControl.hpp"

namespace BrazzGUI {
/**
 * Windows are top-level ParentControls
 * They can also have Menus
 */
using Window = ParentControl<ControlType::Window>;
} // namespace BrazzGUI

#endif