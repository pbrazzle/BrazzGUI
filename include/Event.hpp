#ifndef EVENT
#define EVENT

#include "ControlID.hpp"

namespace BrazzGUI
{
/**
 * TODO document this enum
*/
enum class EventType
{
	QUIT,
	LEFT_CLICK_DOWN,
	CHECK_CHANGED,
	TEXT_CHANGED,
	RESIZED,
	DRAW_BACKGROUND,
	PAINT,
	CHILD_SET_COLORS
};

/**
 * TODO document this class
*/
class Event
{
	private:
		EventType type;
		ControlID control;
		
	public:
		/**
		 * TODO document this function
		*/
		Event(const EventType& t) : control(-1), type(t) { }
		
		/**
		 * TODO document this function
		*/
		Event(const ControlID& id, const EventType& t) : control(id), type(t) { }
		
		/**
		 * TODO document this function
		*/
		ControlID getControl() const { return control; }
		
		/**
		 * TODO document this function
		*/
		EventType getType() const { return type; }
};
}

#endif