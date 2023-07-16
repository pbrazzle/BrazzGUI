#include "TextArea.hpp"

#include "TextControl.test.hpp"

class TextAreaTests : public TextControlTests {
    public:
    std::unique_ptr<Control> getTestInstance() {
        return std::make_unique<TextArea>();
    }
};

TEST_CASE("TextArea Control tests", "[TextArea]") {
    TextAreaTests tests;
    tests.run();
}

TEST_CASE("TextArea TextControl tests", "[TextArea]") {
    TextAreaTests tests;
    tests.runTextTests();
}