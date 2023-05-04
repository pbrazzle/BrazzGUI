#include "Window.hpp"
#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

Window::Window() : Control(ControlCreation::ControlType::Window) { }