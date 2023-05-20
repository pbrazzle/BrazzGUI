#include "Control.test.hpp"
#include "Checkbox.hpp"

class CheckboxTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<Checkbox>(); 
		}
		
		void checkChangedEvent()
		{
			REQUIRE(false);
		}
		
		void clickChangesCheck()
		{
			REQUIRE(false);
		}
};

TEST_CASE("Checkbox Control tests", "[Checkbox]")
{
	CheckboxTests tests;
	tests.run();
}

TEST_CASE("Checkbox creates check changed event", "[Checkbox]")
{
	CheckboxTests tests;
	tests.checkChangedEvent();
}

TEST_CASE("Checkbox checks on and off when clicked", "[Checkbox]")
{
	CheckboxTests tests;
	tests.clickChangesCheck();
}