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
			int run();
			void stop();
			
			void connect(const Event&, const std::function<void(const Event&)>&);
			void postEvent(const Event&);
	};
}

#endif