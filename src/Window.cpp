#include "Window.h"

#include "Win32GUIHandle.h"
#include "BasicEventHandler.h"

Window::Window()
{
	handle = std::shared_ptr<GUIHandle>(new Win32GUIHandle());
	eventHandler = std::shared_ptr<EventHandler>(new BasicEventHandler());
}
		
void Window::show()
{
	setVisible(true);
}

void Window::setVisible(bool visible)
{
	handle->setVisible(visible);
}

void Window::setWidth(int)
{
	
}

void Window::setHeight(int)
{
	
}

void Window::setX(int)
{
	
}

void Window::setY(int)
{
	
}

void Window::setParent(const BasicControl&)
{
	
}

BasicControl* Window::getParent()
{
	return nullptr;
}

void Window::addChild(const BasicControl&)
{
	
}

std::vector<BasicControl*> Window::getChildren()
{
	return std::vector<BasicControl*>();
}

void Window::setClickCallback(std::function<void()> callback)
{
	eventHandler->setCallback(EventType::Click, callback);
}