#ifndef CONTROL_TESTS
#define CONTROL_TESTS

#include <catch2/catch_test_macros.hpp>

#include "Control.hpp"
#include "Window.hpp"
#include "BrazzApp.hpp"

#include <memory>

using namespace BrazzGUI;

class ControlTests
{
	public:
		bool hasWindowText = true;
		int minimumHeight = 30;
		int minimumWidth = 30;
	
		virtual std::unique_ptr<Control> getTestInstance() = 0;
		
		void run()
		{
			SECTION("Control creates", "[Control]")
			{
				Window testWindow;
				CHECK_NOTHROW(getTestInstance());
			}

			SECTION("Control shows", "[Control]")
			{
				Window testWindow;
				auto testControl = getTestInstance();
				CHECK_NOTHROW(testControl->show());
			}

			SECTION("Control resizes", "[Control]")
			{
				Window testWindow;
				auto testControl = getTestInstance();
				auto currentWidth = testControl->getWidth(), currentHeight = testControl->getHeight();
				int newHeight = minimumHeight, newWidth = minimumWidth;
				testControl->setWidth(newHeight);
				testControl->setHeight(newWidth);
				REQUIRE(testControl->getHeight() == newHeight);
				REQUIRE(testControl->getWidth() == newWidth);
			}

			if (hasWindowText)
			{
				SECTION("Control changes text", "[Control]")
				{
					Window testWindow;
					auto testControl = getTestInstance();
					testControl->setText("TEST TEXT");
					REQUIRE(testControl->getText() == "TEST TEXT");
				}
			}

			SECTION("Control repositions", "[Control]")
			{
				Window testWindow;
				auto testControl = getTestInstance();
				auto currentX = testControl->getX(), currentY = testControl->getY();
				testControl->setX(currentX / 2);
				testControl->setY(currentY / 2);
				REQUIRE(testControl->getX() == currentX/2);
				REQUIRE(testControl->getY() == currentY/2);
			}

			SECTION("Control sends clicked signal", "[Control]")
			{
				BrazzApp testApp;
				Window testWindow;
				auto testControl = getTestInstance();
				bool recv = false;
				testApp.connect(Event(testControl->getID(), EventType::LEFT_CLICK_DOWN), 
				[&]()
				{
					recv = true;
					testApp.stop();
				});
				testApp.postEvent(Event(testControl->getID(), EventType::LEFT_CLICK_DOWN));
				testApp.run();
				REQUIRE(recv);
			}
		}
};

#endif