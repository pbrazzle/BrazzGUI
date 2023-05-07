#include <catch2/catch_test_macros.hpp>
#include "Window.hpp"
#include "Textbox.hpp"
#include "BrazzApp.hpp"

using namespace BrazzGUI;

TEST_CASE("Textbox creates", "[Textbox]")
{
	Window testWindow;
	std::unique_ptr<Textbox> testButton;
	CHECK_NOTHROW(testButton.reset(new Textbox()));
}

TEST_CASE("Textbox shows", "[Textbox]")
{
	Window testWindow;
	Textbox testButton;
	CHECK_NOTHROW(testButton.show());
}

TEST_CASE("Textbox resizes", "[Textbox]")
{
	Window testWindow;
	Textbox testButton;
	auto currentWidth = testButton.getWidth(), currentHeight = testButton.getHeight();
	testButton.setWidth(currentWidth / 2);
	testButton.setHeight(currentHeight / 2);
	REQUIRE(testButton.getHeight() == currentHeight/2);
	REQUIRE(testButton.getWidth() == currentWidth/2);
}

TEST_CASE("Textbox changes text", "[Textbox]")
{
	Window testWindow;
	Textbox testButton;
	testButton.setText("TEST TEXT");
	REQUIRE(testButton.getText() == "TEST TEXT");
}

TEST_CASE("Textbox repositions", "[Textbox]")
{
	Window testWindow;
	Textbox testButton;
	auto currentX = testButton.getX(), currentY = testButton.getY();
	testButton.setX(currentX / 2);
	testButton.setY(currentY / 2);
	REQUIRE(testButton.getX() == currentX/2);
	REQUIRE(testButton.getY() == currentY/2);
}

TEST_CASE("Textbox sends clicked signal", "[Textbox]")
{
	BrazzApp testApp;
	Window testWindow;
	Textbox testButton;
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