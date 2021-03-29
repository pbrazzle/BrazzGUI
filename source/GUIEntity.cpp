#include "GUIEntity.hpp"

#include <windows.h>

/*
*	This has been mostly decoupled from Win32 calls
*	setStyle still uses some WinAPI
*	setBgColor still uses the WinAPI color struct
*/

GUIEntity::GUIEntity() { }

GUIEntity::GUIEntity(int a, int b, int c, int d) : x(a), y(b), width(c), height(d) { }

void GUIEntity::create()
{	
	OSInterface::create(this);
	created = true;
	initialize();
}

void GUIEntity::updateSize()
{
	position p;
	OSInterface::handleMessage(this, OS_GETPOS, &pos, 0);
	pos.x = x = p.x;
	pos.y = y = p.y;
	pos.width = width = p.width;
	pos.height = height = p.height;
}

void GUIEntity::resize()
{
	OSInterface::handleMessage(this, OS_SETSIZE, &pos, 0);
}

void GUIEntity::setX(int a)
{
	pos.x = x = a;
	if (created) OSInterface::handleMessage(this, OS_SETPOS, &pos, 0);
}

void GUIEntity::setY(int a)
{
	y = a;
	if (created) OSInterface::handleMessage(this, OS_SETPOS, &pos, 0);
}

void GUIEntity::setWidth(unsigned int a)
{
	pos.width = width = a;
	if (created) OSInterface::handleMessage(this, OS_SETSIZE, &pos, 0);
}

void GUIEntity::setHeight(unsigned int a)
{
	pos.height = height = a;
	if (created) OSInterface::handleMessage(this, OS_SETSIZE, &pos, 0);
}

void GUIEntity::setText(std::string s)
{
	text = s;
	if (created) OSInterface::handleMessage(this, OS_SETTEXT, &s, 0);
}

void GUIEntity::setClassName(std::string s)
{
	if (!created) className = s;
}

void GUIEntity::setBgColor(int r, int g, int b)
{
	bgColor = RGB(r,g,b);
	OSInterface::handleMessage(this, REPAINT, 0, 0);
}

//I could see more ways to expand this function
//e.g, ToggleStyle, addStyle, removeStyle, etc.
void GUIEntity::setStyle(DWORD s)
{
	style = s;
	if (created)
	{
		SetWindowLongPtr(handle, GWL_STYLE, s);
		SetWindowPos(handle, NULL, 0, 0, width, height, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOZORDER);
	}
}

void GUIEntity::setParent(HWND h)
{
	parent = h;
	create();
}

void GUIEntity::setVScroll(bool v)
{
	if (v) style |= WS_VSCROLL;
	else style &= ~WS_VSCROLL;
	if (created)
	{
		SetWindowLongPtr(handle, GWL_STYLE, style);
		SetWindowPos(handle, NULL, 0, 0, width, height, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOZORDER);
	}
}

std::string GUIEntity::getText() 
{
	if (created) OSInterface::handleMessage(this, OS_GETTEXT, &text, 0);
	return text;
}

HWND GUIEntity::getHandle() { return handle; }

int GUIEntity::getX() { return x; }

int GUIEntity::getY() { return y; }

int GUIEntity::getWidth() { return width; }

int GUIEntity::getHeight() { return height; }

void GUIEntity::paint() {}

void GUIEntity::changeSize() {}

void GUIEntity::exitResize() {}

void GUIEntity::destroy() {}

void GUIEntity::click() {}

void GUIEntity::initialize() { }

void GUIEntity::command() {}

int GUIEntity::update() { return 1; }