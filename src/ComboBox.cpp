#include "ComboBox.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

ComboBox::ComboBox() 
	: Control(ControlCreation::ControlType::ComboBox) { }
	
int ComboBox::getHeight() const { return ControlStyling::getComboBoxHeight(id); }