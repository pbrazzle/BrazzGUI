#include "BrazzApp.hpp"
#include "EventHandling/EventMaker.hpp"

using namespace BrazzGUI;

int BrazzApp::run() 
{
	auto event = EventHandling::getNextEvent();
	
	while (event.getType() != EventHandling::EventType::QUIT)
	{
		//TODO pass event somewhere...
		event = EventHandling::getNextEvent();
	}
	return 0; 
}

void BrazzApp::stop() 
{ 
	EventHandling::postStopEvent();
}