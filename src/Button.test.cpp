#include <catch2/catch_test_macros.hpp>
#include "Window.hpp"
#include "Button.hpp"
#include "BrazzApp.hpp"

using namespace BrazzGUI;

TEST_CASE("Button creates", "[Button]")
{
	Window testWindow;
	std::unique_ptr<Button> testButton;
	CHECK_NOTHROW(testButton.reset(new Button()));
}

TEST_CASE("Button shows", "[Button]")
{
	Window testWindow;
	Button testButton;
	CHECK_NOTHROW(testButton.show());
}

TEST_CASE("Button resizes", "[Button]")
{
	Window testWindow;
	Button testButton;
	auto currentWidth = testButton.getWidth(), currentHeight = testButton.getHeight();
	testButton.setWidth(currentWidth / 2);
	testButton.setHeight(currentHeight / 2);
	REQUIRE(testButton.getHeight() == currentHeight/2);
	REQUIRE(testButton.getWidth() == currentWidth/2);
}

TEST_CASE("Button changes text", "[Button]")
{
	Window testWindow;
	Button testButton;
	testButton.setText("TEST TEXT");
	REQUIRE(testButton.getText() == "TEST TEXT");
}

TEST_CASE("Button repositions", "[Button]")
{
	Window testWindow;
	Button testButton;
	auto currentX = testButton.getX(), currentY = testButton.getY();
	testButton.setX(currentX / 2);
	testButton.setY(currentY / 2);
	REQUIRE(testButton.getX() == currentX/2);
	REQUIRE(testButton.getY() == currentY/2);
}

TEST_CASE("Button sends clicked signal", "[Button]")
{
	BrazzApp testApp;
	Window testWindow;
	Button testButton;
	bool recv = false;
	testApp.connect(Event(testButton.getID(), EventType::LEFT_CLICK_DOWN), 
	[&]()
	{
		recv = true;
		testApp.stop();
	});
	testApp.postEvent(Event(testButton.getID(), EventType::LEFT_CLICK_DOWN));
	testApp.run();
	REQUIRE(recv);
}