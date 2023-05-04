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