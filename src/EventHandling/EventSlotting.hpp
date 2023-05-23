#ifndef EVENT_SLOTS
#define EVENT_SLOTS

#include "Event.hpp"

#include <functional>

namespace BrazzGUI::EventHandling
{
	void connect(const Event&, const std::function<void(const Event&)>&);
	
	void runSlots(const Event&);
}

#endif