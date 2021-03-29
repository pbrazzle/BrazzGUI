#include "ControlGroup.hpp"
#include "GUIEntity.hpp"

#include <windows.h>

ControlGroup::ControlGroup() : ControlGroup(0,0,100,100) { }

ControlGroup::ControlGroup(int x, int y, int width, int height) : DrawableGUIEntity(x,y,width,height) 
{ 
	setClassName("BWindow");
	setStyle(WS_CHILD | WS_VISIBLE | WS_VSCROLL);
}

void ControlGroup::initialize()
{
	SCROLLINFO sc;
	sc.cbSize = sizeof(SCROLLINFO);
	sc.fMask = SIF_POS;
	sc.nMin = 0;
	sc.nMax = 100;
	
	SetScrollInfo(getHandle(), SB_VERT, &sc, TRUE);
}

void ControlGroup::addChild(GUIEntity& child)
{
	child.setParent(getHandle());
}