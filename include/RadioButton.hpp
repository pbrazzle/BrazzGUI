#ifndef RADIOBUTTON
#define RADIOBUTTON

#include "Control.hpp"

namespace BrazzGUI {
/**
 * The RadioButton allows the user to select between 2 or more exclusive options
 * RadioButtons are composed in RadioButtonGroups
 */
using RadioButton = BasicControl<ControlType::RadioButton>;
} // namespace BrazzGUI

#endif