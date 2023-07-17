#ifndef BRAZZGUI_PANEL
#define BRAZZGUI_PANEL

#include "ParentControl.hpp"

namespace BrazzGUI {

/**
 * The Panel Control simply groups child Controls
 * This allows for more complex layouts, as each Panel can handle its own layout
 */
class Panel : public ParentControl {
    public:
    /**
     * Creates a new Panel
     */
    Panel();
};

} // namespace BrazzGUI

#endif