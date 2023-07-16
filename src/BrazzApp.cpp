#include "BrazzApp.hpp"

#include "EventHandling/EventMaker.hpp"
#include "EventHandling/EventSlotting.hpp"

#include <iostream>

using namespace BrazzGUI;

int BrazzApp::run() {
    auto event = EventHandling::getNextEvent();

    while (event.getType() != EventType::QUIT) {
        EventHandling::runSlots(event);
        event = EventHandling::getNextEvent();
    }
    return 0;
}

void BrazzApp::stop() { EventHandling::postStopEvent(); }

void BrazzApp::connect(const Event& e,
                       const std::function<void(const Event&)>& slot) {
    EventHandling::connect(e, slot);
}

void BrazzApp::postEvent(const Event& e) { EventHandling::postEvent(e); }