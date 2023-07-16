#ifndef TEXT_CONTROL
#define TEXT_CONTROL

#include "Control.hpp"

namespace BrazzGUI {
/**
 * TODO document this class
 */
class TextControl : public Control {
    public:
    /**
     * TODO document this function
     */
    TextControl(const ControlCreation::ControlType& type);

    /**
     * TODO document this function
     */
    virtual ~TextControl() = 0;
};
} // namespace BrazzGUI

#endif