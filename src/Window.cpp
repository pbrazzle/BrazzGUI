#include "Window.hpp"

using namespace BrazzGUI;

Window::Window() :
    ParentControl<ControlType::Window>(),
    menuHandler(Handlers::getDefaultMenuHandler()) {}

Window::Window(std::unique_ptr<Handlers::MenuHandler> mHandler) :
    ParentControl<ControlType::Window>(),
    menuHandler(std::move(mHandler)) {}

void Window::addMenuItem(const MenuItem& item) {
    menuHandler->addTopLevelItem(*this, item);
}