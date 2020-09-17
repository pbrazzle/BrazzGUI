#include "Menu.hpp"

Menu::Menu(std::string t)
{
	setHandle(CreateMenu());
	setText(t);
	AppendMenu((HMENU) getHandle(), MF_STRING, NULL, t.c_str());
}