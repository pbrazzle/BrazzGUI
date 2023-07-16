#include "Control.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

Control::Control(const ControlCreation::ControlType &type)
    : id(ControlCreation::createControl(type)) {
    backgroundColor = {255, 255, 255};

    EventHandling::connect(
        Event(id, EventType::CHILD_SET_COLORS), [&](const Event &e) {
            ControlStyling::setBackgroundColor(id, getBackgroundColor());
        });
}

Control::~Control() {}

void Control::show() { ControlStyling::show(id); }

void Control::setX(const int &x) { ControlStyling::setX(id, x); }
void Control::setY(const int &y) { ControlStyling::setY(id, y); }
void Control::setWidth(const int &width) {
    ControlStyling::setWidth(id, width);
}
void Control::setHeight(const int &height) {
    ControlStyling::setHeight(id, height);
}

void Control::setPosition(const int &x, const int &y, const int &width,
                          const int &height) {
    setX(x);
    setY(y);
    setWidth(width);
    setHeight(height);
}

void Control::setBackgroundColor(Color bg) {
    backgroundColor = bg;
    ControlStyling::setBackgroundColor(id, bg);
}

void Control::setTextColor(Color t) {
    textColor = t;
    ControlStyling::setTextColor(id, t);
}

void Control::setText(const std::string &text) {
    ControlStyling::setText(id, text);
}

void Control::setFontSize(const int &s) {
    font.setSize(s);
    ControlStyling::setFont(id, font);
}

int Control::getX() const { return ControlStyling::getX(id); }
int Control::getY() const { return ControlStyling::getY(id); }
int Control::getWidth() const { return ControlStyling::getWidth(id); }
int Control::getHeight() const { return ControlStyling::getHeight(id); }

std::string Control::getText() const { return ControlStyling::getText(id); }

ControlID Control::getID() const { return id; }

int Control::getFontSize() const { return font.getSize(); }

Color Control::getBackgroundColor() const { return backgroundColor; }
Color Control::getTextColor() const { return textColor; }