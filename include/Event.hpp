#ifndef EVENT
#define EVENT

#include "ControlID.hpp"

namespace BrazzGUI {
/**
 * Enum to specify different types of Events
 * Each unique type can have a different handler depending on the Control
 * associated with it
 */
enum class EventType {
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
 * BrazzGUI applications are based on Events
 * Events are created and handled to trigger response callback functions
 */
class Event {

    private:
    // The type of this Event
    EventType type;

    // The ControlID of the associated Control for this Event
    ControlID control;

    public:
    /**
     * Creates a new Event with no associated Control
     *
     * @param t EventType of this Event
     */
    Event(const EventType& t) : control(-1), type(t) {}

    /**
     * Creates a new Event
     *
     * @param id ControlID of the handling Control
     * @param t EventType of this Event
     */
    Event(const ControlID& id, const EventType& t) : control(id), type(t) {}

    /**
     * Returns the ControlID associated with this Event
     *
     * @return ControlID associated with this Event
     */
    ControlID getControl() const { return control; }

    /**
     * Returns the EventType of this Event
     *
     * @return EventType of this Event
     */
    EventType getType() const { return type; }
};
} // namespace BrazzGUI

#endif