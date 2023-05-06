#include "BrazzApp.hpp"
#include "Window.hpp"
#include "Button.hpp"

#include <windows.h>
#include <iostream>
#include <exception>

using namespace BrazzGUI;

int main()
{
	BrazzApp myApp;
	
	Window myWindow;
	
	Button myButton;
	myButton.setWidth(100);
	myButton.setHeight(100);
	myButton.setX(100);
	myButton.setY(100);
	myWindow.addControl(myButton);
	
	myWindow.show();
	
	return myApp.run();
}