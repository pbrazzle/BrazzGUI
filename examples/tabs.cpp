#include "BrazzApp.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "ComboBox.hpp"
#include "Event.hpp"
#include "Label.hpp"
#include "Panel.hpp"
#include "RadioButton.hpp"
#include "TabGroup.hpp"
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

    Button tabButton;
    tabButton.setText("TABS");

    Button tabButton2;
    tabButton2.setText("TABS2");

    TabGroup myTabs;
    myTabs.addTab("test", &tabButton);
    myTabs.addTab("test", &tabButton2);
    myWindow.addControl(myTabs, LayoutType::CENTER);

    myWindow.show();

    return myApp.run();
}