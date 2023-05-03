#ifndef BRAZZAPP
#define BRAZZAPP

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
	};
}

#endif