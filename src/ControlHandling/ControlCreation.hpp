#ifndef CONTROL_CREATION
#define CONTROL_CREATION

#include "ControlID.hpp"

namespace BrazzGUI::ControlCreation
{
/**
 * TODO document this enum
*/
enum class ControlType
{
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
 * TODO document this function
*/
ControlID createControl(const ControlType& type);
}

#endif