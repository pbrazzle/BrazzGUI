#include "DrawableGUIEntity.hpp"
#include "Brush.hpp"

#include <windows.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

DrawableGUIEntity::DrawableGUIEntity() { }

DrawableGUIEntity::DrawableGUIEntity(int x, int y, int w, int h) : GUIEntity(x,y,w,h) { }

DrawableGUIEntity::~DrawableGUIEntity()
{
	DeleteDC(buffer);
}

void DrawableGUIEntity::initialize()
{
	resetBuffer();
}

void DrawableGUIEntity::resetBuffer()
{
	if (getHandle() != NULL)
	{
		//Delete current buffer
		DeleteDC(buffer);
		
		//Reset Buffers
		HDC hdc = GetDC(getHandle());

		buffer = CreateCompatibleDC(hdc);
		
		RECT r;
		GetClientRect(getHandle(), &r);
		
		HBITMAP b = CreateCompatibleBitmap(hdc, r.right, r.bottom);

		HBITMAP oldbmp = (HBITMAP)SelectObject(buffer, b);
		DeleteObject(oldbmp);

		ReleaseDC(getHandle(), hdc);
		
		//Paint background
		Gdiplus::Graphics g(buffer);
		g.Clear(Gdiplus::Color::White);
	}
}

void DrawableGUIEntity::setWidth(unsigned int w) 
{ 
	GUIEntity::setWidth(w);
	resetBuffer();
}

void DrawableGUIEntity::setHeight(unsigned int h) 
{ 
	GUIEntity::setHeight(h);
	resetBuffer();
}

void DrawableGUIEntity::paint()
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(getHandle(), &ps);
	
	RECT r;
	GetClientRect(getHandle(), &r);

	BitBlt(
		hdc,
		0, 0,
		r.right, r.bottom,
		buffer,
		0, 0,
		SRCCOPY);
	EndPaint(getHandle(), &ps);
}