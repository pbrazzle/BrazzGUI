#ifndef LABEL
#define LABEL

#include "Control.hpp"

namespace BrazzGUI {
/**
 * Labels are Controls with static readonly text
 * Labels can control their background and text colors
 */
using Label = BasicControl<ControlType::Label>;
} // namespace BrazzGUI

#endif