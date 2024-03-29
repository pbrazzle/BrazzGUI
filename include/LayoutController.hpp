#ifndef LAYOUT_CONTROLLER
#define LAYOUT_CONTROLLER

#include "Control.hpp"

namespace BrazzGUI {
/**
 * LayoutType determines how a Control is positioned with a LayoutController
 * EAST, WEST take 20% of their respective sides
 * NORTH, SOUTH take 20% and take priority from EAST, WEST
 * CENTER takes the rest of the available space
 */
enum class LayoutType { CENTER, EAST, WEST, NORTH, SOUTH };

template<ControlType type> class ParentControl;

// TODO Fix case where there is no CENTER Control
/**
 * The LayoutController automatically repositions Controls to adhere to a
 * specific layout
 * When a parent Control is resized, the LayoutController will update all child
 * controls
 */
template<ControlType type> class LayoutController {
    private:
    // Pointer to the parent Control
    ParentControl<type>* parent;

    // Pointers to the child Controls
    Control *center, *east, *west, *north, *south;

    public:
    /**
     * Creates a new LayoutController
     */
    LayoutController();

    /**
     * Sets the parent of this LayoutController
     *
     * @param parent New parent Control for this LayoutController
     */
    void setParent(ParentControl<type>* parent);

    /**
     * Sets a child Control of this LayoutController
     * Overwrites any child Control in the same spot
     *
     * @param child New child Control for this LayoutController
     * @param type LayoutType for the child Control
     */
    void addControl(Control*, const LayoutType);

    /**
     * Updates the positions of the child Controls
     */
    void updatePositions() const;
};

} // namespace BrazzGUI

#endif