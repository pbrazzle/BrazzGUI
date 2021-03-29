#ifndef MENUITEM
#define MENUITEM

#include <windows.h>
#include <string>

class MenuItem
{
	private:
		unsigned int id, style;
		
		std::string text;
		
		
	public:
		MenuItem();
		MenuItem(std::string);
		
		unsigned int getStyle();
		std::string getText();
		
		void addMenuItem(MenuItem);
		HMENU handle;
};

#endif