#include "Label.hpp"

Label::Label(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("STATIC");
	setStyle(WS_CHILD | WS_VISIBLE);
	setText("Label");
}

Label::Label() : Label(100,100,0,0) { }