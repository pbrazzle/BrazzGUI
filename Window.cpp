#include "Window.h"

Window::Window()
{
	handler = EventHandler();
	obj = GUIObject("Window", "...");
	handler.attachGUIObject(obj);
}

void Window::show()
{
	obj.show();
}