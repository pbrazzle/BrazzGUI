#include "BrazzApp.hpp"
#include "Window.hpp"

#include <windows.h>

using namespace BrazzGUI;

int main()
{
	BrazzApp myApp;
	
	Window myWindow;
	myWindow.show();

	return myApp.run();
}