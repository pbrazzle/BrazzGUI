#ifndef CONTROL_CREATION
#define CONTROL_CREATION

#include "Control.hpp"
#include "ControlID.hpp"

namespace BrazzGUI::ControlCreation {
/**
 * Creates a new Control using the OS API
 *
 * @param type Type of Control to create
 * @return ID of the created Control
 */
ControlID createControl(const BrazzGUI::ControlType& type);
} // namespace BrazzGUI::ControlCreation

#endif