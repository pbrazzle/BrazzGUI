#include "ComboBox.hpp"

#include <windows.h>
#include <CommCtrl.h>

ComboBox::ComboBox(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName(WC_COMBOBOX);
	setStyle(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_HASSTRINGS);
}

ComboBox::ComboBox() : ComboBox(0,0,100,100) { }