#include "Button.hpp"

#include "Control.test.hpp"

class ButtonTests : public ControlTests {
    public:
    std::unique_ptr<Control> getTestInstance() {
        return std::make_unique<Button>();
    }
};

TEST_CASE("Button Control tests", "[Button]") {
    ButtonTests tests;
    tests.run();
}