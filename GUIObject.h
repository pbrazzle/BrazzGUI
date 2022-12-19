#ifndef GUIOBJECT
#define GUIOBJECT

#include <windows.h>
#include <string>

#include "EventHandler.h"

class GUIObject
{
	private:
		HWND hwnd;
		
	public:
		GUIObject();
		GUIObject(std::string, std::string, EventHandler*);
		
		void show();
};

#endif