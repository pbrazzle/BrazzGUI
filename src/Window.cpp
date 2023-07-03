#include "Window.hpp"
#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

Window::Window() : Control(ControlCreation::ControlType::Window) { 
	layout.setParent(this);

	EventHandling::connect(Event(id, EventType::RESIZED), [&](const Event& e) 
	{ 
		layout.updatePositions();
	});
}

void Window::addControl(Control& child)
{
	ControlStyling::setChild(getID(), child.getID());
}

void Window::addControl(Control& child, const LayoutType layoutType)
{
	ControlStyling::setChild(getID(), child.getID());
	layout.addControl(&child, layoutType);
}

void Window::updateLayout(){
	layout.updatePositions();
}

int Window::getClientWidth(){
	return ControlStyling::getClientWidth(id);
}

int Window::getClientHeight(){
	return ControlStyling::getClientHeight(id);
}