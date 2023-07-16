#ifndef COMBOBOX
#define COMBOBOX

#include "Control.hpp"

namespace BrazzGUI {
/**
 * The ComboBox control contains a dropdown list of options for the user to
 * select As of now, ComboBoxes cannot control their colors or fonts
 */
class ComboBox : public Control {
    public:
    /**
     * Creates a ComboBox
     */
    ComboBox();

    /**
     * Returns the height of the ComboBox
     *
     * @return Height of the ComboBox
     */
    int getHeight() const override;
};
} // namespace BrazzGUI

#endif