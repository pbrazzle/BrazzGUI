#ifndef BASICEVENTHANDLER
#define BASICEVENTHANDLER

#include "EventHandler.h"

#include <map>

class BasicEventHandler : public EventHandler
{
	private:
		std::map<EventType, std::function<void()>> handlerMap;
		
	public:
		BasicEventHandler();
		
		void setCallback(EventType, std::function<void()>);
		
		void click();
};

#endif