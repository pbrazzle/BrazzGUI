#ifndef LAYOUT_CONTROLLER
#define LAYOUT_CONTROLLER

#include "Control.hpp"

namespace BrazzGUI
{

class ParentControl;

enum class LayoutType
{
    CENTER,
    EAST,
    WEST,
    NORTH,
    SOUTH
};

class LayoutController{
    private:
        ParentControl* parent;
        Control* center, *east, *west, *north, *south;

    public:
        LayoutController();

        void setParent(ParentControl*);
        void addControl(Control*, const LayoutType);

        void updatePositions() const;
};

}

#endif