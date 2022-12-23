#ifndef EVENTHANDLER
#define EVENTHANDLER

#include <functional>

enum class EventType
{
	Click
};

class EventHandler
{
	public:
		//Set callbacks
		virtual void setCallback(EventType, std::function<void()>) = 0;
		
		//Several GUI events
		virtual void click() = 0;
};

#endif