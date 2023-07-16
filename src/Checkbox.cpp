#include "Checkbox.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

Checkbox::Checkbox() : Control(ControlCreation::ControlType::Checkbox) {}

bool Checkbox::isChecked() { return ControlStyling::isChecked(id); }

void Checkbox::setCheck(const bool& c) { ControlStyling::setCheck(id, c); }