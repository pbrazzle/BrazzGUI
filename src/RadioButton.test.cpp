#include "RadioButton.hpp"
#include "Control.test.hpp"

class RadioButtonTests : public ControlTests {
    public:
    std::unique_ptr<Control> getTestInstance() {
        return std::make_unique<RadioButton>();
    }
};

TEST_CASE("RadioButton Control tests", "[RadioButton]") {
    RadioButtonTests tests;
    tests.run();
}