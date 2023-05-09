#include "Control.test.hpp"
#include "RadioButton.hpp"

class RadioButtonTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<RadioButton>(); 
		}
};

TEST_CASE("RadioButton Control tests", "[RadioButton]")
{
	RadioButtonTests tests;
	tests.run();
}