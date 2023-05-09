#include "Control.test.hpp"
#include "TextArea.hpp"

class TextAreaTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<TextArea>(); 
		}
};

TEST_CASE("TextArea Control tests", "[TextArea]")
{
	TextAreaTests tests;
	tests.run();
}	