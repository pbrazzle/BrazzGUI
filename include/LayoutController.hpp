#ifndef LAYOUT_CONTROLLER
#define LAYOUT_CONTROLLER

#include "Control.hpp"

namespace BrazzGUI {

class ParentControl;

/**
 * TODO document this enum
 */
enum class LayoutType { CENTER, EAST, WEST, NORTH, SOUTH };

/**
 * TODO document this class
 */
class LayoutController {
    private:
    ParentControl *parent;
    Control *center, *east, *west, *north, *south;

    public:
    /**
     * TODO document this function
     */
    LayoutController();

    /**
     * TODO document this function
     */
    void setParent(ParentControl *);

    /**
     * TODO document this function
     */
    void addControl(Control *, const LayoutType);

    /**
     * TODO document this function
     */
    void updatePositions() const;
};

} // namespace BrazzGUI

#endif