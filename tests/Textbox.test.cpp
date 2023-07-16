#include "Textbox.hpp"

#include "TextControl.test.hpp"

class TextboxTests : public TextControlTests {
    public:
    std::unique_ptr<Control> getTestInstance() {
        return std::make_unique<Textbox>();
    }
};

TEST_CASE("Textbox Control tests", "[Textbox]") {
    TextboxTests tests;
    tests.run();
}

TEST_CASE("Textbox TextControl tests", "[Textbox]") {
    TextboxTests tests;
    tests.runTextTests();
}