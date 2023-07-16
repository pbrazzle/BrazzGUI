#ifndef BRAZZAPP
#define BRAZZAPP

#include "Event.hpp"

#include <functional>

namespace BrazzGUI
{
	/**
	*	The BrazzApp class is responsible for the GUI Event loop
	*   It has control over starting and stopping the Event loop
	*/
	class BrazzApp
	{
		public:
			/**
			 * Starts handling Events sent to this BrazzApp.
			 * Function will hang until the BrazzApp receives a stop Event.
			 * 
			 * @return 0 if there is no error. Nonzero error code otherwise.
			*/
			int run();

			/**
			 * Sends a stop Event to this BrazzApp.
			*/
			void stop();
			
			/**
			 * Connects a callback function to an Event template.
			 * When this BrazzApp receives an Event with the same type and id as the template,
			 * it will run the connected callback functions.
			 * An Event template can be connected to multiple callbacks.
			 * 
			 * @param event Event template to connect to callback function
			 * @param callback Callback function to run whenever this BrazzApp receives the Event template
			*/
			void connect(const Event& event, const std::function<void(const Event&)>& callback);

			/**
			 * Sends an Event to this BrazzApp's Event queue
			 * 
			 * @param event Event to be placed in the queue
			*/
			void postEvent(const Event& event);
	};
}

#endif