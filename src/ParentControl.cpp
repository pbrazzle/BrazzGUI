#include "ParentControl.hpp"

#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

template<ControlType type>
ParentControl<type>::ParentControl() : Control(type) {
    layout.setParent(this);
    EventHandling::connect(Event(id, EventType::RESIZED),
                           [&](const Event& e) { layout.updatePositions(); });
}

template<ControlType type>
void ParentControl<type>::addControl(Control& child) {
    ControlStyling::setChild(getID(), child.getID());
}

template<ControlType type>
void ParentControl<type>::addControl(Control& child, const LayoutType type) {
    ControlStyling::setChild(getID(), child.getID());
    layout.addControl(&child, type);
}

template<ControlType type> void ParentControl<type>::updateLayout() {
    layout.updatePositions();
}

template<ControlType type> int ParentControl<type>::getClientWidth() {
    return ControlStyling::getClientWidth(getID());
}

template<ControlType type> int ParentControl<type>::getClientHeight() {
    return ControlStyling::getClientHeight(getID());
}

template class ParentControl<ControlType::Window>;
template class ParentControl<ControlType::Panel>;