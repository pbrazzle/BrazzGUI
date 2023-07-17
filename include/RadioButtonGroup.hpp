#ifndef RADIOBUTTON_GROUP
#define RADIOBUTTON_GROUP

#include "Control.hpp"

namespace BrazzGUI {
/**
 * RadioButtonGroups compose RadioButtons
 * This Control handles the active choice in the group, checking the active
 * choice and unchecking all others
 *
 * TODO add functions to add RadioButtons
 */
class RadioButtonGroup : public Control {
    public:
    /**
     * Creates a new RadioButtonGroup
     */
    RadioButtonGroup();
};
} // namespace BrazzGUI

#endif