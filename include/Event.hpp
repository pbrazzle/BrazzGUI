#ifndef EVENT
#define EVENT

#include "ControlID.hpp"

namespace BrazzGUI
{
	enum class EventType
	{
		QUIT,
		LEFT_CLICK_DOWN,
		CHECK_CHANGED,
		TEXT_CHANGED
	};
	
	class Event
	{
		private:
			EventType type;
			ControlID control;
			
		public:
			Event(const EventType& t) : control(-1), type(t) { }
			Event(const ControlID& id, const EventType& t) : control(id), type(t) { }
			
			ControlID getControl() const { return control; }
			EventType getType() const { return type; }
	};
}

#endif