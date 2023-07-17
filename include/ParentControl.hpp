#ifndef BRAZZGUI_PARENT_CONTROL
#define BRAZZGUI_PARENT_CONTROL

#include "Control.hpp"
#include "LayoutController.hpp"

namespace BrazzGUI {

/**
 * A ParentControl can have child Controls associated with it
 * ParentControls use a LayoutController to manage the layout of its children
 */
class ParentControl : public Control {
    private:
    LayoutController layout;

    public:
    /**
     * Creates a new ParentControl
     *
     * @param type ControlType of this Control
     */
    ParentControl(const ControlCreation::ControlType type);

    /**
     * Virtual destructor
     * Makes this class abstract
     */
    virtual ~ParentControl() = 0 {}

    /**
     * Adds a new child Control to this ParentControl
     *
     * @param child Child Control to be added
     */
    void addControl(Control& child);

    /**
     * Adds a new child Control to this ParentControl
     * Also specifies the LayoutType for this child
     *
     * @param child Child Control to be added
     * @param layoutType LayoutType of the child
     */
    void addControl(Control& child, const LayoutType layoutType);

    /**
     * Updates the position of all child Controls based on the layout
     */
    void updateLayout();

    /**
     * Retuns the width of this Controls client area in pixels
     *
     * @return Width of the client area in pixels
     */
    [[nodiscard]] int getClientWidth();

    /**
     * Returns the height of this Controls client area in pixels
     *
     * @return Height of the client area in pixels
     */
    [[nodiscard]] int getClientHeight();
};

} // namespace BrazzGUI

#endif