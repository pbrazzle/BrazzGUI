#include "Brush.hpp"

#include <windows.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

Brush::Brush(DrawableGUIEntity &w) 
{ 
	bitmap = w.buffer;
	handle = w.getHandle();
}

void Brush::fillBackground()
{
	Gdiplus::Graphics g(bitmap);
	g.Clear(Gdiplus::Color::White);
	InvalidateRect(handle, NULL, false);
}

void Brush::drawLine(int x1, int y1, int x2, int y2)
{
	Gdiplus::Graphics g(bitmap);
	Gdiplus::Pen p(Gdiplus::Color(255, 0, 0, 0));
	g.DrawLine(&p, x1, y1, x2, y2);
	InvalidateRect(handle, NULL, false);
}

void Brush::drawRect(int x, int y, int width, int height)
{
	Gdiplus::Graphics g(bitmap);
	Gdiplus::Pen p(Gdiplus::Color(255, 0, 0, 0));
	g.DrawRectangle(&p, x, y, width, height);
	InvalidateRect(handle, NULL, false);
}

void Brush::drawText(std::string text, int x, int y)
{
	Gdiplus::Graphics g(bitmap);
	Gdiplus::FontFamily fontFamily(L"Times New Roman");
	Gdiplus::Font font(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	Gdiplus::PointF pointF(x, y);
	Gdiplus::SolidBrush solidBrush(Gdiplus::Color(255, 0, 0, 0));

	std::wstring t = std::wstring(text.begin(), text.end());
	g.DrawString(t.c_str(), -1, &font, pointF, &solidBrush);
	InvalidateRect(handle, NULL, false);
}