#ifndef BUTTON
#define BUTTON

#include "Control.hpp"

namespace BrazzGUI {
/**
 * The Button Control class displays a push button in the BrazzApp GUI.
 * Generally, Buttons are used to handle click Events from the user.
 * A Button always uses the default color scheme, and cannot currently be
 * changed. A Button can control its font size.
 */
using Button = BasicControl<ControlType::Button>;
} // namespace BrazzGUI

#endif