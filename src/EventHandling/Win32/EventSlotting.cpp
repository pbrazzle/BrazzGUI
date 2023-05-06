#include "EventHandling/EventSlotting.hpp"

#include <map>

using namespace BrazzGUI::EventHandling;
using namespace BrazzGUI;

auto slotMap = std::map<Event, std::function<void(void)>, std::function<bool(const Event&, const Event&)>>{
	[](const Event& e1, const Event& e2)
	{
		if (e1.getControl() < e2.getControl()) return true;
		return e1.getType() < e2.getType();
	}
};

void BrazzGUI::EventHandling::connect(const Event& e, const std::function<void(void)>& slot)
{
	slotMap[e] = slot;
}

void BrazzGUI::EventHandling::runSlots(const Event& e)
{
	if (slotMap.count(e))
		slotMap[e]();
}