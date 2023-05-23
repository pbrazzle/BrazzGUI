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
	
	Button myButton;
	myButton.setWidth(100);
	myButton.setHeight(100);
	myButton.setX(0);
	myButton.setY(0);
	myApp.connect(Event(myButton.getID(), EventType::LEFT_CLICK_DOWN), [](const Event&) { std::cout << "click!\n"; });
	myWindow.addControl(myButton);
	
	Label myLabel;
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