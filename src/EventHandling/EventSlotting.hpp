#ifndef EVENT_SLOTS
#define EVENT_SLOTS

#include "Event.hpp"

#include <functional>

namespace BrazzGUI::EventHandling {
/**
 * Assigns a callback function for a given Event template
 * Event templates include a ControlID and an EventType
 *
 * @param event Event template to connect to
 * @param callback Callback function to assign to the Event
 */
void connect(const Event& event,
             const std::function<void(const Event&)>& callback);

/**
 * Runs all callback functions assigned to this Event
 */
void runSlots(const Event&);
} // namespace BrazzGUI::EventHandling

#endif