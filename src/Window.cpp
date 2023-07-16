#include "Window.hpp"

#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

Window::Window() : ParentControl(ControlCreation::ControlType::Window) {
    EventHandling::connect(
        Event(id, EventType::DRAW_BACKGROUND), [&](const Event& e) {
            ControlStyling::drawBackground(id, getBackgroundColor());
        });
}