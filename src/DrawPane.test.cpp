#include "Control.test.hpp"
#include "DrawPane.hpp"

class DrawPaneTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<DrawPane>(); 
		}
};

TEST_CASE("DrawPane Control tests", "[DrawPane]")
{
	DrawPaneTests tests;
	tests.run();
}