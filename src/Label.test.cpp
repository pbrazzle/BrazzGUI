#include "Control.test.hpp"
#include "Label.hpp"

class LabelTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<Label>(); 
		}
};

TEST_CASE("Label Control tests", "[Label]")
{
	LabelTests tests;
	tests.run();
}