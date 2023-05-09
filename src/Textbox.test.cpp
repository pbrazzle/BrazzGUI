#include "Control.test.hpp"
#include "Textbox.hpp"

class TextboxTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<Textbox>(); 
		}
};

TEST_CASE("Textbox Control tests", "[Textbox]")
{
	TextboxTests tests;
	tests.run();
}