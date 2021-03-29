#include "Pane.hpp"

#include <windows.h>

Pane::Pane() : Pane(0,0,100,100) { }

Pane::Pane(int x, int y, int w, int h) : DrawableGUIEntity(x,y,w,h) 
{ 
	setClassName("BWindow");
	setStyle(WS_CHILD | WS_VISIBLE);
}