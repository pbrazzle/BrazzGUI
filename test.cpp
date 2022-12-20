//Using BrazzGUI classes to create a Window

#include <windows.h>

#include "Window.h"
#include "Button.h"
#include "BrazzGUIApp.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{	
	BrazzGUIApp myApp;
	Window myWindow;
	myWindow.show();
	
	Button myButton;
	myApp.run();
	
	return 0;
}