#include "ParentControl.hpp"
#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

ParentControl::ParentControl(const ControlCreation::ControlType type) : Control(type) { 
    layout.setParent(this);
    EventHandling::connect(Event(id, EventType::RESIZED), [&](const Event& e) 
	{ 
		layout.updatePositions();
	});
}

void ParentControl::addControl(Control& child) {
    ControlStyling::setChild(getID(), child.getID());
}

void ParentControl::addControl(Control& child, const LayoutType type) {
    ControlStyling::setChild(getID(), child.getID());
	layout.addControl(&child, type);
}

void ParentControl::updateLayout() {
    layout.updatePositions();
}

int ParentControl::getClientWidth() {
    return ControlStyling::getClientWidth(getID());
}

int ParentControl::getClientHeight() {
    return ControlStyling::getClientHeight(getID());
}