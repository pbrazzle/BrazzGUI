#include "LayoutController.hpp"
#include "Window.hpp"

#include <exception>
#include <system_error>

using namespace BrazzGUI;

LayoutController::LayoutController() : 
    parent(nullptr), north(nullptr), 
    center(nullptr), south(nullptr),
    east(nullptr), west(nullptr) { }

void checkParentChild(const Control* parent, const Control* child){
    //if (parent && child)
        //throw std::logic_error("Control::isParent not implemented");
}

void LayoutController::setParent(Window* p) {
    checkParentChild(p, center);
    checkParentChild(p, north);
    checkParentChild(p, south);
    checkParentChild(p, east);
    checkParentChild(p, west);

    parent = p;
}

void LayoutController::addControl(Control* c, const LayoutType type){
    checkParentChild(parent, c);

    switch (type)
    {
        case LayoutType::CENTER:
            center = c;
            break;
        case LayoutType::NORTH:
            north = c;
            break;
        case LayoutType::SOUTH:
            south = c;
            break;
        case LayoutType::EAST:
            east = c;
            break;
        case LayoutType::WEST:
            west = c;
            break;
    }
}

#include <iostream>

void LayoutController::updatePositions() const{
    // TODO update positions of all Controls
    // EAST, WEST take 20% of their respective sides
    // NORTH, SOUTH take 20% and take priority from EAST, WEST
    // CENTER takes the rest of the available space

    if (!parent) return;

    auto width = parent->getClientWidth();
    auto height = parent->getClientHeight();
    int x = 0, y = 0;

    auto remainingHeight = height;
    auto remainingWidth = width;

    std::cout << "Layout updating: Parent width " << width << " height " << height << std::endl;

    if (north)
    {
        auto northHeight = static_cast<int>(height * 0.2);
        north->setPosition(0, 0, width, northHeight);
        remainingHeight -= northHeight;
        y += northHeight;
    }
    if (south)
    {
        auto southHeight = static_cast<int>(height * 0.2);
        south->setPosition(0, height - southHeight, width, southHeight);
        remainingHeight -= southHeight;
    }
    if (east)
    {
        auto eastWidth = static_cast<int>(width * 0.2);
        east->setPosition(0, y, eastWidth, remainingHeight);
        remainingWidth -= eastWidth;
        x += eastWidth;
    }
    if (west)
    {
        auto westWidth = static_cast<int>(width * 0.2);
        west->setPosition(width-westWidth, y, westWidth, remainingHeight);
        remainingWidth -= westWidth;
    }
    if (center)
    {
        center->setPosition(x, y, remainingWidth, remainingHeight);
    }
}