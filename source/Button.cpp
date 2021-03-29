#include "Button.hpp"

#include <windows.h>
#include <string>

Button::Button() : Button(0,0,100,100) { }

Button::Button(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("BUTTON");
	setStyle(WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON);
	clickAction = NULL;
}

void Button::click()
{
	if (clickAction != NULL) clickAction();
}

void Button::setClickAction(void (*f)()) { clickAction = f; }
