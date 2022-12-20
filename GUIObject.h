#ifndef GUIOBJECT
#define GUIOBJECT

#include <windows.h>
#include <string>

class GUIObject
{
	private:
		HWND hwnd;
		
	public:
		GUIObject();
		GUIObject(std::string, std::string);
		
		void show();
		
		HWND getHandle();
};

#endif