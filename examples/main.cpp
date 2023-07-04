#include "BrazzApp.hpp"
#include "Window.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "RadioButton.hpp"
#include "Checkbox.hpp"
#include "Textbox.hpp"
#include "ComboBox.hpp"
#include "Event.hpp"
#include "TextArea.hpp"

#include <windows.h>
#include <iostream>
#include <exception>

using namespace BrazzGUI;

int main()
{
	BrazzApp myApp;
	
	Window myWindow;
	myWindow.setBackgroundColor({255, 0, 0});
	
	Button myButton;
	myButton.setBackgroundColor({0, 255, 0});
	myButton.setWidth(100);
	myButton.setHeight(100);
	myButton.setX(0);
	myButton.setY(0);
	myButton.setFontSize(10);
	myApp.connect(Event(myButton.getID(), EventType::LEFT_CLICK_DOWN), [&](const Event&) 
	{ 
		std::cout << "click!\n";
		myButton.setFontSize(myButton.getFontSize() + 1);
	});
	myWindow.addControl(myButton);
	
	Label myLabel;
	myLabel.setBackgroundColor({0, 255, 0});
	myLabel.setPosition(100, 0, 100, 100);
	myApp.connect(Event(myLabel.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myLabel);
	
	RadioButton myRadioButton;
	myRadioButton.setPosition(0, 100, 100, 100);
	myApp.connect(Event(myRadioButton.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myRadioButton);
	
	Textbox myTextbox;
	myTextbox.setPosition(100, 100, 100, 100);
	myApp.connect(Event(myTextbox.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myApp.connect(Event(myTextbox.getID(), EventType::TEXT_CHANGED), [](const Event&) { std::cout << "text changed!\n"; });
	myWindow.addControl(myTextbox);
	
	Checkbox myCheckbox;
	myCheckbox.setPosition(200, 0, 100, 100);
	myApp.connect(Event(myCheckbox.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myCheckbox);
	
	ComboBox myComboBox;
	myComboBox.setText("TEST");
	myComboBox.setPosition(200, 100, 100, 30);
	myApp.connect(Event(myComboBox.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myComboBox);
	
	TextArea myTextArea;
	myTextArea.setPosition(300, 0, 100, 100);
	myApp.connect(Event(myTextArea.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myTextArea);
	
	myWindow.show();
	
	return myApp.run();
}