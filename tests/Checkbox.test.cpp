#include "Checkbox.hpp"

#include "BrazzApp.hpp"
#include "Window.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace BrazzGUI;

TEST_CASE("Checkbox creates check changed event", "[Checkbox]") {
    BrazzApp testApp;
    Window testWindow;
    Checkbox testControl;
    bool recv = false;
    testApp.connect(Event(testControl.getID(), EventType::CHECK_CHANGED),
                    [&](const Event&) { recv = true; });
    testControl.setCheck(!testControl.isChecked());
    testApp.stop();
    testApp.run();
    REQUIRE(recv);
}

TEST_CASE("Checkbox checks on and off when clicked", "[Checkbox]") {
    BrazzApp testApp;
    Window testWindow;
    Checkbox testControl;
    bool recv = false;
    testApp.connect(Event(testControl.getID(), EventType::CHECK_CHANGED),
                    [&](const Event&) { recv = true; });
    testApp.postEvent(Event(testControl.getID(), EventType::LEFT_CLICK_DOWN));
    testApp.stop();
    testApp.run();
    REQUIRE(recv);
}