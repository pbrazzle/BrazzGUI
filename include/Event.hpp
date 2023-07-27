#ifndef EVENT
#define EVENT

#include "ControlID.hpp"

#include <memory>

namespace BrazzGUI {
/**
 * Enum to specify different types of Events
 * Each unique type can have a different handler depending on the Control
 * associated with it
 */
enum class EventType {
    QUIT,
    LEFT_CLICK_DOWN,
    RIGHT_CLICK_DOWN,
    CHECK_CHANGED,
    TEXT_CHANGED,
    RESIZED,
    DRAW_BACKGROUND,
    PAINT,
    CHILD_SET_COLORS,
    TAB_CHANGED,
    KEY_DOWN,
    SCROLL_UP,
    SCROLL_DOWN
};

class EventData {
    public:
    virtual std::unique_ptr<EventData> clone() const = 0;
};

enum EventKey : char { LSHIFT, RSHIFT, ENTER, BACKSPACE };

class KeyEventData : public EventData {
    private:
    EventKey key;

    public:
    KeyEventData(EventKey k) : key(k) {}

    std::unique_ptr<EventData> clone() const {
        return std::make_unique<KeyEventData>(key);
    }

    EventKey getKey() const { return key; }
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

    // The data for this Event
    std::unique_ptr<EventData> data;

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

    Event(const ControlID& id, const EventType& t,
          std::unique_ptr<EventData> d) :
        control(id),
        type(t),
        data(std::move(d)) {}

    /*
     * TODO document this function
     */
    Event(const Event& rhs) {
        type = rhs.type;
        control = rhs.control;
        if (rhs.data.get()) data = std::move(rhs.data->clone());
        else data = nullptr;
    }

    /**
     * TODO document this function
     */
    Event& operator=(const Event& rhs) {
        type = rhs.type;
        control = rhs.control;
        if (rhs.data.get()) data = std::move(rhs.data->clone());
        else data = nullptr;
        return *this;
    }

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

    const EventData* getData() const { return data.get(); }
};
} // namespace BrazzGUI

#endif