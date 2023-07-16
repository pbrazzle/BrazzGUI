#ifndef LABEL
#define LABEL

#include "Control.hpp"

namespace BrazzGUI {
/**
 * Labels are Controls with static readonly text
 * Labels can control their background and text colors
 */
class Label : public Control {
    public:
    /**
     * Creates a new Label
     */
    Label();
};
} // namespace BrazzGUI

#endif