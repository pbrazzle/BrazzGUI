#include "Window.hpp"

using namespace BrazzGUI;

Window::Window() : ParentControl<ControlType::Window>(), menu(*this) {}

void Window::addMenuItem(const MenuItem& item) { menu.addItem(item); }