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