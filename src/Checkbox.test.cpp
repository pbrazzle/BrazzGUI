#include "Control.test.hpp"
#include "Checkbox.hpp"

class CheckboxTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<Checkbox>(); 
		}
};

TEST_CASE("Checkbox Control tests", "[Checkbox]")
{
	CheckboxTests tests;
	tests.run();
}