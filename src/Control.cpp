#include "Control.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

Control::Control(const ControlCreation::ControlType& type) : id(ControlCreation::createControl(type)) { }
Control::~Control() { }

void Control::show() { ControlStyling::show(id); }

void Control::setX(const int& x) { ControlStyling::setX(id, x); }
void Control::setY(const int& y) { ControlStyling::setY(id, y); }
void Control::setWidth(const int& width) { ControlStyling::setWidth(id, width); }
void Control::setHeight(const int& height) { ControlStyling::setHeight(id, height); }

void Control::setText(const std::string& text) { ControlStyling::setText(id, text); }

int Control::getX() const { return ControlStyling::getX(id); }
int Control::getY() const { return ControlStyling::getY(id); }
int Control::getWidth() const { return ControlStyling::getWidth(id); }
int Control::getHeight() const { return ControlStyling::getHeight(id); }

std::string Control::getText() const { return ControlStyling::getText(id); }