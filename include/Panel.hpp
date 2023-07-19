#ifndef BRAZZGUI_PANEL
#define BRAZZGUI_PANEL

#include "ParentControl.hpp"

namespace BrazzGUI {

// TODO Panels aren't coloring their background
/**
 * The Panel Control simply groups child Controls
 * This allows for more complex layouts, as each Panel can handle its own layout
 */
using Panel = ParentControl<ControlType::Panel>;
} // namespace BrazzGUI

#endif