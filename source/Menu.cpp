#include "Menu.hpp"

Menu::Menu()
{
	handle = CreateMenu();
	updated = false;
}

Menu::~Menu()
{
	DestroyMenu(handle);
}

void Menu::addMenuItem(MenuItem mi)
{
	AppendMenu(handle, mi.getStyle(), (UINT_PTR) mi.handle, mi.getText().c_str());
	updated = true;
}
