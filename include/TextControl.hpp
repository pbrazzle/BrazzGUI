#ifndef TEXT_CONTROL
#define TEXT_CONTROL

#include "Control.hpp"

namespace BrazzGUI {
/**
 * TextControls include all Controls that handle user text input
 */
class TextControl : public Control {
    public:
    /**
     * Creates a new TextControl
     *
     * @param type ControlType for this Control
     */
    TextControl(const ControlCreation::ControlType& type);

    /**
     * Virtual destructor
     * Makes this an abstract class
     */
    virtual ~TextControl() = 0;
};
} // namespace BrazzGUI

#endif