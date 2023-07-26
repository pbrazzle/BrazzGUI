#include "BrazzApp.hpp"
#include "MenuItem.hpp"
#include "Window.hpp"

#include <exception>
#include <iostream>
#include <windows.h>

using namespace BrazzGUI;

int main() {
    BrazzApp myApp;

    Window myWindow;

    MenuItem item("Item");
    MenuItem subItem("SubItem");
    item.addSubItem(subItem);
    myApp.connect(Event(subItem.getID(), EventType::LEFT_CLICK_DOWN),
                  [&](const Event&) { std::cout << "subitem click!\n"; });
    myWindow.addMenuItem(item);

    myWindow.show();

    return myApp.run();
}