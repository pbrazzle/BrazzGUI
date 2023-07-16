#ifndef DRAW_PANE
#define DRAW_PANE

#include "Control.hpp"

namespace BrazzGUI {
/**
 * TODO which event does DrawPane handle?
 * A DrawPane appears as a blank window, but it provides a ??? Event to perform
 * drawing operations
 * This allows for custom graphics in BrazzGUI applications
 */
class DrawPane : public Control {
    public:
    /**
     * Creates a DrawPane
     */
    DrawPane();
};
} // namespace BrazzGUI

#endif