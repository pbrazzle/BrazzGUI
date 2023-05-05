#include "ControlHandling/ControlStyling.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"

#include <windows.h>

using namespace BrazzGUI;

HWND getHandleFromID(const ControlID& id)
{
	auto osData = static_cast<const ControlHandling::Win32Data&>(ControlHandling::getDataFromID(id));
	return osData.getHandle();
}

void ControlStyling::show(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	ShowWindow(handle, SW_NORMAL);
}

void ControlStyling::setX(const ControlID& id, const int& x) 
{ 
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	SetWindowPos(handle, NULL, x, windowPos.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void ControlStyling::setY(const ControlID& id, const int& y) 
{ 
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	SetWindowPos(handle, NULL, windowPos.left, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void ControlStyling::setWidth(const ControlID& id, const int& width) 
{ 
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	SetWindowPos(handle, NULL, 0, 0, width, windowPos.bottom-windowPos.top, SWP_NOMOVE | SWP_NOZORDER);
}

void ControlStyling::setHeight(const ControlID& id, const int& height) 
{ 
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	SetWindowPos(handle, NULL, 0, 0, windowPos.right-windowPos.left, height, SWP_NOMOVE | SWP_NOZORDER);
}

void ControlStyling::setText(const ControlID& id, const std::string& text) 
{ 
	auto handle = getHandleFromID(id);
	SetWindowText(handle, text.c_str());
}

int ControlStyling::getX(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	return windowPos.left;
}

int ControlStyling::getY(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	return windowPos.top;
}

int ControlStyling::getWidth(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	return windowPos.right-windowPos.left;
}

int ControlStyling::getHeight(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	RECT windowPos;
	GetWindowRect(handle, &windowPos);
	return windowPos.bottom-windowPos.top;
}

std::string ControlStyling::getText(const ControlID& id)
{
	auto handle = getHandleFromID(id);
	auto textLength = GetWindowTextLength(handle);
	char* textBuf = new char[textLength+1];
	GetWindowText(handle, textBuf, textLength+1);
	std::string textStr(textBuf);
	delete [] textBuf;
	return textStr;
}