#include "ComboBox.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

int ComboBox::getHeight() const {
    return ControlStyling::getComboBoxHeight(id);
}