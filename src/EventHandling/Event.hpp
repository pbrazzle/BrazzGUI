#ifndef EVENT
#define EVENT

namespace BrazzGUI
{
	namespace EventHandling
	{
		enum class EventType
		{
			QUIT
		};
		
		class Event
		{
			private:
				EventType type;
				int destination;
				
			public:
				Event(const EventType& t) : type(t) { }
				
				EventType getType() const { return type; }
		};
	}
}

#endif