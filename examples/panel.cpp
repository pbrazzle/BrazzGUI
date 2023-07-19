#include "Panel.hpp"

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

    Panel myPanel;
    myWindow.addControl(myPanel, LayoutType::CENTER);

    Button myButton;
    myButton.setBackgroundColor({0, 255, 0});
    myButton.setTextColor({255, 0, 0});
    myButton.setFontSize(10);
    myApp.connect(Event(myButton.getID(), EventType::LEFT_CLICK_DOWN),
                  [&](const Event&) {
                      std::cout << "click!\n";
                      myButton.setFontSize(myButton.getFontSize() + 1);
                  });
    myPanel.addControl(myButton, LayoutType::NORTH);

    Button button2;
    myPanel.addControl(button2, LayoutType::SOUTH);

    myWindow.show();

    return myApp.run();
}