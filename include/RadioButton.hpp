#ifndef RADIOBUTTON
#define RADIOBUTTON

#include "Control.hpp"

namespace BrazzGUI {
/**
 * The RadioButton allows the user to select between 2 or more exclusive options
 * RadioButtons are composed in RadioButtonGroups
 */
class RadioButton : public Control {
    public:
    /**
     * Creates a new RadioButton
     */
    RadioButton();
};
} // namespace BrazzGUI

#endif