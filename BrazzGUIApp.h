#ifndef BRAZZGUIAPP
#define BRAZZGUIAPP

#include "EventHandler.h"

class BrazzGUIApp
{
	private:
		EventHandler handler;
		
	public:
		BrazzGUIApp();
		
		void run();
};

#endif