#ifndef EVENTHANDLER
#define EVENTHANDLER

#include <windows.h>

LRESULT CALLBACK dispatchEvent(HWND, UINT, WPARAM, LPARAM);

class EventHandler
{
	public:
		EventHandler();
		
		LRESULT handleEvent(HWND, UINT, WPARAM, LPARAM);
};

#endif