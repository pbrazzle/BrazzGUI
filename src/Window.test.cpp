#include "Control.test.hpp"
#include "Window.hpp"

class WindowTests : public ControlTests
{
	public:
		std::unique_ptr<Control> getTestInstance() 
		{ 
			return std::make_unique<Window>(); 
		}
};

TEST_CASE("Window Control tests", "[Window]")
{
	WindowTests tests;
	tests.minimumHeight = 150;
	tests.minimumWidth = 150;
	
	tests.run();
}