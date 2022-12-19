#ifndef EVENTHANDLER
#define EVENTHANDLER

#include <windows.h>

class EventHandler
{
	public:
		EventHandler();
		
		LRESULT handleEvent(HWND, UINT, WPARAM, LPARAM);
};

#endif