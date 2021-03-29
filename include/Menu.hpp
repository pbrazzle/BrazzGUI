#ifndef MENU
#define MENU

#include <string>
#include <windows.h>

#include "MenuItem.hpp"

class Menu
{
	private:
		friend class Window;
		
		bool updated;
		
	protected:
		HMENU handle;
	
	public:
		Menu();
		~Menu();
		
		void addMenuItem(MenuItem);
};

#endif