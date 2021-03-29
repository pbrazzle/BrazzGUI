#include "MenuItem.hpp"

MenuItem::MenuItem(std::string t) : text(t), style(MF_STRING | MF_POPUP) 
{ 
	handle = CreatePopupMenu();
}

MenuItem::MenuItem() : text("Default"), style(MF_STRING | MF_POPUP) { }

void MenuItem::addMenuItem(MenuItem mi)
{
	AppendMenu(handle, MF_STRING | MF_POPUP, (UINT_PTR) mi.handle, mi.getText().c_str());
}

std::string MenuItem::getText() { return text; }

unsigned int MenuItem::getStyle() { return style; } 