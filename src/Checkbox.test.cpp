#include "Checkbox.hpp"
#include "Control.test.hpp"

class CheckboxTests : public ControlTests {
    public:
    std::unique_ptr<Control> getTestInstance() {
        return std::make_unique<Checkbox>();
    }

    void checkChangedEvent() {
        BrazzApp testApp;
        Window testWindow;
        Checkbox testControl;
        bool recv = false;
        testApp.connect(Event(testControl.getID(), EventType::CHECK_CHANGED),
                        [&](const Event &) { recv = true; });
        testControl.setCheck(!testControl.isChecked());
        testApp.stop();
        testApp.run();
        REQUIRE(recv);
    }

    void clickChangesCheck() {
        BrazzApp testApp;
        Window testWindow;
        Checkbox testControl;
        bool recv = false;
        testApp.connect(Event(testControl.getID(), EventType::CHECK_CHANGED),
                        [&](const Event &) { recv = true; });
        testApp.postEvent(
            Event(testControl.getID(), EventType::LEFT_CLICK_DOWN));
        testApp.stop();
        testApp.run();
        REQUIRE(recv);
    }
};

TEST_CASE("Checkbox Control tests", "[Checkbox]") {
    CheckboxTests tests;
    tests.run();
}

TEST_CASE("Checkbox creates check changed event", "[Checkbox]") {
    CheckboxTests tests;
    tests.checkChangedEvent();
}

TEST_CASE("Checkbox checks on and off when clicked", "[Checkbox]") {
    CheckboxTests tests;
    tests.clickChangesCheck();
}