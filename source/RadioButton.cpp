#include "RadioButton.hpp"

#include <windows.h>

RadioButton::RadioButton(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("BUTTON");
	setStyle(WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON);
}

RadioButton::RadioButton() : RadioButton(0,0,100,100) { }

void RadioButton::click()
{
	clicked = true;
}