#ifndef EVENT_MAKER
#define EVENT_MAKER

#include "Event.hpp"

namespace BrazzGUI::EventHandling {
/**
 *	Pops the next GUI Event from the OS message queue
 *	/return A GUI Event
 */
Event getNextEvent();

/**
 *	Enqueues a stop Event to the OS message queue
 */
void postStopEvent();

/**
 *	Enqueues an Event to the BrazzGUI Event queue
 */
void postEvent(const Event&);
} // namespace BrazzGUI::EventHandling

#endif