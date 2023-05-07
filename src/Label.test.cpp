#include <catch2/catch_test_macros.hpp>
#include "Window.hpp"
#include "Label.hpp"
#include "BrazzApp.hpp"

using namespace BrazzGUI;

TEST_CASE("Label creates", "[Label]")
{
	Window testWindow;
	std::unique_ptr<Label> testButton;
	CHECK_NOTHROW(testButton.reset(new Label()));
}

TEST_CASE("Label shows", "[Label]")
{
	Window testWindow;
	Label testButton;
	CHECK_NOTHROW(testButton.show());
}

TEST_CASE("Label resizes", "[Label]")
{
	Window testWindow;
	Label testButton;
	auto currentWidth = testButton.getWidth(), currentHeight = testButton.getHeight();
	testButton.setWidth(currentWidth / 2);
	testButton.setHeight(currentHeight / 2);
	REQUIRE(testButton.getHeight() == currentHeight/2);
	REQUIRE(testButton.getWidth() == currentWidth/2);
}

TEST_CASE("Label changes text", "[Label]")
{
	Window testWindow;
	Label testButton;
	testButton.setText("TEST TEXT");
	REQUIRE(testButton.getText() == "TEST TEXT");
}

TEST_CASE("Label repositions", "[Label]")
{
	Window testWindow;
	Label testButton;
	auto currentX = testButton.getX(), currentY = testButton.getY();
	testButton.setX(currentX / 2);
	testButton.setY(currentY / 2);
	REQUIRE(testButton.getX() == currentX/2);
	REQUIRE(testButton.getY() == currentY/2);
}

TEST_CASE("Label sends clicked signal", "[Label]")
{
	BrazzApp testApp;
	Window testWindow;
	Label testButton;
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