#ifndef BRAZZGUIWINDOW
#define BRAZZGUIWINDOW

#include "GUIObject.h"
#include "EventHandler.h"

class Window
{
	private:
		GUIObject obj;
		EventHandler handler;
		
	public:
		Window();
		
		void show();
};

#endif