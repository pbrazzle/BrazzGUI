#include <catch2/catch_test_macros.hpp>
#include "Window.hpp"

using BrazzGUI::Window;

TEST_CASE("Window creates", "[Window]")
{
	std::unique_ptr<Window> testWindow;
	CHECK_NOTHROW(testWindow.reset(new Window()));
}

TEST_CASE("Window shows", "[Window]")
{
	Window testWindow;
	CHECK_NOTHROW(testWindow.show());
}

TEST_CASE("Window resizes", "[Window]")
{
	Window testWindow;
	auto currentWidth = testWindow.getWidth(), currentHeight = testWindow.getHeight();
	testWindow.setWidth(currentWidth / 2);
	testWindow.setHeight(currentHeight / 2);
	REQUIRE(testWindow.getHeight() == currentHeight/2);
	REQUIRE(testWindow.getWidth() == currentWidth/2);
}

TEST_CASE("Window changes text", "[Window]")
{
	Window testWindow;
	testWindow.setText("TEST TEXT");
	REQUIRE(testWindow.getText() == "TEST TEXT");
}

TEST_CASE("Window repositions", "[Window]")
{
	Window testWindow;
	auto currentX = testWindow.getX(), currentY = testWindow.getY();
	testWindow.setX(currentX / 2);
	testWindow.setY(currentY / 2);
	REQUIRE(testWindow.getX() == currentX/2);
	REQUIRE(testWindow.getY() == currentY/2);
}

TEST_CASE("Window sends clicked signal", "[Window]")
{
	REQUIRE(false);
}