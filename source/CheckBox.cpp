#include "CheckBox.hpp"

#include <windows.h>

CheckBox::CheckBox(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("BUTTON");
	setStyle(WS_CHILD | WS_VISIBLE | BS_CHECKBOX);
}

CheckBox::CheckBox() : CheckBox(0,0,100,100) { }

void CheckBox::click()
{
	if (checked)
	{
		SendMessage(getHandle(), BM_SETCHECK, BST_UNCHECKED, 0);
		checked = false;
	} else
	{
		SendMessage(getHandle(), BM_SETCHECK, BST_CHECKED, 0);
		checked = true;
	}
}

bool CheckBox::isChecked() { return checked; }