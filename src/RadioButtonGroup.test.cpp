#include "Control.test.hpp"
#include "RadioButtonGroup.hpp"

class RadioButtonGroupTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<RadioButtonGroup>(); 
		}
};

TEST_CASE("RadioButtonGroup Control tests", "[RadioButtonGroup]")
{
	RadioButtonGroupTests tests;
	tests.run();
}