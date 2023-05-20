#include "Checkbox.hpp"
#include "ControlHandling/ControlCreation.hpp"

using namespace BrazzGUI;

Checkbox::Checkbox() : Control(ControlCreation::ControlType::Checkbox) { }

bool Checkbox::isChecked() { return false; }

void Checkbox::setCheck(const bool&) { }