#include "BrazzApp.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "ComboBox.hpp"
#include "Control.hpp"
#include "DrawPane.hpp"
#include "Label.hpp"
#include "Panel.hpp"
#include "RadioButton.hpp"
#include "RadioButtonGroup.hpp"
#include "TextArea.hpp"
#include "Textbox.hpp"
#include "Window.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace BrazzGUI;

template<class ControlClass> void basicControlTests() {
    SECTION("Control creates", "[Control]") {
        Window testWindow;
        CHECK_NOTHROW(ControlClass());
    }

    SECTION("Control shows", "[Control]") {
        Window testWindow;
        auto testControl = ControlClass();
        CHECK_NOTHROW(testControl.show());
    }

    SECTION("Control resizes", "[Control]") {
        Window testWindow;
        auto testControl = ControlClass();
        auto currentWidth = testControl.getWidth(),
             currentHeight = testControl.getHeight();
        int newHeight = 200, newWidth = 200;
        testControl.setWidth(newHeight);
        testControl.setHeight(newWidth);
        REQUIRE(testControl.getHeight() == newHeight);
        REQUIRE(testControl.getWidth() == newWidth);
    }

    // TODO make static function to determine if a ControlType has text
    if (false) {
        SECTION("Control changes text", "[Control]") {
            Window testWindow;
            auto testControl = ControlClass();
            testControl.setText("TEST TEXT");
            REQUIRE(testControl.getText() == "TEST TEXT");
        }
    }

    SECTION("Control repositions", "[Control]") {
        Window testWindow;
        auto testControl = ControlClass();
        auto currentX = testControl.getX(), currentY = testControl.getY();
        testControl.setX(currentX / 2);
        testControl.setY(currentY / 2);
        REQUIRE(testControl.getX() == currentX / 2);
        REQUIRE(testControl.getY() == currentY / 2);
    }

    SECTION("Control sends clicked signal", "[Control]") {
        BrazzApp testApp;
        Window testWindow;
        auto testControl = ControlClass();
        bool recv = false;
        testApp.connect(Event(testControl.getID(), EventType::LEFT_CLICK_DOWN),
                        [&](const Event&) {
                            recv = true;
                            testApp.stop();
                        });
        testApp.postEvent(
            Event(testControl.getID(), EventType::LEFT_CLICK_DOWN));
        testApp.run();
        REQUIRE(recv);
    }
}

#define BASIC_TESTS(className)                                                 \
    TEST_CASE(#className " BasicControl tests", "[" #className "]") {          \
        basicControlTests<className>();                                        \
    }

BASIC_TESTS(Window)
BASIC_TESTS(Button)
BASIC_TESTS(Label)
BASIC_TESTS(Textbox)
BASIC_TESTS(TextArea)
BASIC_TESTS(DrawPane)
BASIC_TESTS(Checkbox)
BASIC_TESTS(RadioButton)
BASIC_TESTS(RadioButtonGroup)
BASIC_TESTS(ComboBox)
BASIC_TESTS(Panel)