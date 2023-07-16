#include "BrazzApp.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "ComboBox.hpp"
#include "Event.hpp"
#include "Label.hpp"
#include "RadioButton.hpp"
#include "TextArea.hpp"
#include "Textbox.hpp"
#include "Window.hpp"

#include <exception>
#include <iostream>
#include <windows.h>

using namespace BrazzGUI;

int main() {
    BrazzApp myApp;

    Window myWindow;
    std::cout << "Window ID is " << myWindow.getID().getValue() << std::endl;

    Button myButton;
    myButton.setFontSize(24);
    myWindow.addControl(myButton, LayoutType::CENTER);

    Button myButton2;
    myButton2.setFontSize(24);
    myWindow.addControl(myButton2, LayoutType::WEST);

    Button myButton3;
    myButton3.setFontSize(24);
    myWindow.addControl(myButton3, LayoutType::EAST);

    Button myButton4;
    myButton4.setFontSize(24);
    myWindow.addControl(myButton4, LayoutType::NORTH);

    Button myButton5;
    myButton5.setFontSize(24);
    myWindow.addControl(myButton5, LayoutType::SOUTH);

    myWindow.show();

    return myApp.run();
}