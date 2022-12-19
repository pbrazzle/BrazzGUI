#include "Window.h"

Window::Window()
{
	handler = EventHandler();
	obj = GUIObject("Window", "...", &handler);
}

void Window::show()
{
	obj.show();
}