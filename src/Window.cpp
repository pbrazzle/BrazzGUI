#include "Window.hpp"
#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

Window::Window() : id(ControlCreation::createControl(ControlCreation::ControlType::Window)) { }

void Window::show()
{
	ControlStyling::show(id);
}