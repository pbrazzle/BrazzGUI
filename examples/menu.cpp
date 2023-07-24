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

    myWindow.addMenuItem(MenuItem());

    myWindow.show();

    return myApp.run();
}