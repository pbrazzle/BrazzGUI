#ifndef BRAZZAPP
#define BRAZZAPP

#include "Event.hpp"

#include <functional>

namespace BrazzGUI
{
	/**
	*	The BrazzApp class is responsible for the GUI message loop
	*   It has control over starting and stopping the loop
	*/
	class BrazzApp
	{
		public:
			/**
			 * TODO document this function
			*/
			int run();

			/**
			 * TODO document this function
			*/
			void stop();
			
			/**
			 * TODO document this function
			*/
			void connect(const Event&, const std::function<void(const Event&)>&);

			/**
			 * TODO document this function
			*/
			void postEvent(const Event&);
	};
}

#endif