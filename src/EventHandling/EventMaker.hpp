#ifndef EVENT_MAKER
#define EVENT_MAKER

#include "EventHandling/Event.hpp"

namespace BrazzGUI
{
	namespace EventHandling
	{
		/**
		*	Pops the next GUI Event from the OS message queue
		*	/return A GUI Event
		*/
		Event getNextEvent();
		
		/**
		*	Enqueues a stop Event to the OS message queue
		*/
		void postStopEvent();
	}
}

#endif