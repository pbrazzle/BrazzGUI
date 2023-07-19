#include "Control.test.hpp"

// TODO add this to TextControl.test.cpp
class TextControlTests : public ControlTests {
    public:
    void runTextTests() {
        SECTION("Text Changed Event") {
            BrazzApp testApp;
            Window testWindow;
            auto testControl = getTestInstance();
            bool recv = false;
            testApp.connect(
                Event(testControl->getID(), EventType::TEXT_CHANGED),
                [&](const Event&) { recv = true; });
            testControl->setText("TEST");
            testApp.stop();
            testApp.run();
            REQUIRE(recv);
        }
    }
};