#include <catch2/catch_test_macros.hpp>
#include "Window.hpp"
#include "Checkbox.hpp"
#include "BrazzApp.hpp"

using namespace BrazzGUI;

TEST_CASE("Checkbox creates", "[Checkbox]")
{
	Window testWindow;
	std::unique_ptr<Checkbox> testButton;
	CHECK_NOTHROW(testButton.reset(new Checkbox()));
}

TEST_CASE("Checkbox shows", "[Checkbox]")
{
	Window testWindow;
	Checkbox testButton;
	CHECK_NOTHROW(testButton.show());
}

TEST_CASE("Checkbox resizes", "[Checkbox]")
{
	Window testWindow;
	Checkbox testButton;
	auto currentWidth = testButton.getWidth(), currentHeight = testButton.getHeight();
	testButton.setWidth(currentWidth / 2);
	testButton.setHeight(currentHeight / 2);
	REQUIRE(testButton.getHeight() == currentHeight/2);
	REQUIRE(testButton.getWidth() == currentWidth/2);
}

TEST_CASE("Checkbox changes text", "[Checkbox]")
{
	Window testWindow;
	Checkbox testButton;
	testButton.setText("TEST TEXT");
	REQUIRE(testButton.getText() == "TEST TEXT");
}

TEST_CASE("Checkbox repositions", "[Checkbox]")
{
	Window testWindow;
	Checkbox testButton;
	auto currentX = testButton.getX(), currentY = testButton.getY();
	testButton.setX(currentX / 2);
	testButton.setY(currentY / 2);
	REQUIRE(testButton.getX() == currentX/2);
	REQUIRE(testButton.getY() == currentY/2);
}

TEST_CASE("Checkbox sends clicked signal", "[Checkbox]")
{
	BrazzApp testApp;
	Window testWindow;
	Checkbox testButton;
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