#include "BrazzApp.hpp"
#include "DrawPane.hpp"
#include "Window.hpp"

#include <exception>
#include <iostream>
#include <windows.h>

using namespace BrazzGUI;

int main() {
    BrazzApp myApp;

    Window myWindow;

    DrawPane myPane;
    myPane.setColor({255, 0, 0});
    myWindow.addControl(myPane, LayoutType::CENTER);

    myApp.connect(Event(myPane.getID(), EventType::PAINT), [&](const Event&) {
        std::cout << "draw!\n";
        myPane.drawLine(0, 0, 100, 100);
    });
    myApp.connect(Event(myWindow.getID(), EventType::PAINT),
                  [](const Event&) { std::cout << "window draw\n"; });

    myWindow.show();

    return myApp.run();
}