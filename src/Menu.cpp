#include "Menu.hpp"

#include "Window.hpp"

using namespace BrazzGUI;

Menu::Menu(const Window& parent) :
    handler(Handlers::createMenuHandler(Handlers::MenuType::MenuBar,
                                        ControlID(-1))),
    parentID(parent.getID()) {
    handler->registerMenu(parent);
}

void Menu::addItem(const MenuItem& item) { handler->addItem(item); }