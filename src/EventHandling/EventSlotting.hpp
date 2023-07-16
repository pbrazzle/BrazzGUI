#ifndef EVENT_SLOTS
#define EVENT_SLOTS

#include "Event.hpp"

#include <functional>

namespace BrazzGUI::EventHandling {
/**
 * TODO document this function
 */
void connect(const Event &, const std::function<void(const Event &)> &);

/**
 * TODO document this function
 */
void runSlots(const Event &);
} // namespace BrazzGUI::EventHandling

#endif