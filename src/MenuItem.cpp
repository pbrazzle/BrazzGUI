#include "MenuItem.hpp"

using namespace BrazzGUI;

MenuItem::MenuItem() {
    id = ControlID();
    handler = Handlers::createMenuHandler(Handlers::MenuType::MenuItem, id);
}

MenuItem::MenuItem(const std::string& t) : MenuItem() {
    text = t;
    handler->setText(t);
}

void MenuItem::addSubItem(const MenuItem& item) { handler->addItem(item); }

ControlID MenuItem::getID() const { return id; }

std::string MenuItem::getText() const { return text; }

void MenuItem::setText(const std::string& t) {
    text = t;
    handler->setText(t);
}