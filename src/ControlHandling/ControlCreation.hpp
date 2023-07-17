#ifndef CONTROL_CREATION
#define CONTROL_CREATION

#include "ControlID.hpp"

namespace BrazzGUI::ControlCreation {
/**
 * Enum for all types of Controls
 */
enum class ControlType {
    Window,
    Button,
    Label,
    Textbox,
    TextArea,
    DrawPane,
    Checkbox,
    RadioButton,
    RadioButtonGroup,
    ComboBox,
    Panel
};

/**
 * Creates a new Control using the OS API
 *
 * @param type Type of Control to create
 * @return ID of the created Control
 */
ControlID createControl(const ControlType& type);
} // namespace BrazzGUI::ControlCreation

#endif