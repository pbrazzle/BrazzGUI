#ifndef EVENTHANDLER
#define EVENTHANDLER

#include "GUIObject.h"

#include <windows.h>

LRESULT CALLBACK dispatchEvent(HWND, UINT, WPARAM, LPARAM);

class EventHandler
{
	public:
		EventHandler();
		
		void attachGUIObject(GUIObject);
		
		LRESULT handleEvent(HWND, UINT, WPARAM, LPARAM);
};

#endif