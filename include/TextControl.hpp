#ifndef TEXT_CONTROL
#define TEXT_CONTROL

#include "Control.hpp"

namespace BrazzGUI {
/**
 * TextControls include all Controls that handle user text input
 */
template<ControlType type> class TextControl : public Control {
    public:
    /**
     * Creates a new TextControl
     *
     * @param type ControlType for this Control
     */
    TextControl();
};
} // namespace BrazzGUI

#endif