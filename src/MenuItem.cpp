#include "MenuItem.hpp"

using namespace BrazzGUI;

MenuItem::MenuItem() :
    handler(Handlers::createMenuHandler(Handlers::MenuType::MenuItem)) {}

void MenuItem::addSubItem(const MenuItem& item) { handler->addItem(item); }
