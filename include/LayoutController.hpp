#ifndef LAYOUT_CONTROLLER
#define LAYOUT_CONTROLLER

#include "Control.hpp"

namespace BrazzGUI
{

class Window;

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
        Window* parent;
        Control* center, *east, *west, *north, *south;

    public:
        LayoutController();

        void setParent(Window*);
        void addControl(Control*, const LayoutType);

        void updatePositions() const;
};

}

#endif