#include "EventHandling/EventMaker.hpp"
#include "Event.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"

#include <windows.h>
#include <queue>

using namespace BrazzGUI::EventHandling;
using namespace BrazzGUI;

std::queue<Event> eventQueue;

LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto idVal = static_cast<int>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	
    switch (uMsg)
    {
	case WM_LBUTTONDOWN:
		eventQueue.push(Event(idVal, EventType::LEFT_CLICK_DOWN));
		return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool handleMessage()
{
	MSG msg = { };
	BOOL result = GetMessage(&msg, NULL, 0, 0);
	if (result == 0) return false;
	
	//TODO Check for error
	//if (result == -1) throw -1;
	
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	return true;
}

Event BrazzGUI::EventHandling::getNextEvent() 
{ 
	while (eventQueue.empty())
	{		
		if (!handleMessage()) return Event(EventType::QUIT);
	}
	auto next = eventQueue.front();
	eventQueue.pop();
	return next;
}

void BrazzGUI::EventHandling::postStopEvent() 
{
	auto& topWindowData = BrazzGUI::ControlHandling::getTopWindows();
	for (int i = 0; i < topWindowData.size(); i++)
	{
		auto win32Data = static_cast<const ControlHandling::Win32Data*>(topWindowData[i].get());
		auto handle = win32Data->getHandle();
		PostMessage(handle, WM_CLOSE, 0, 0);
	}
}

void BrazzGUI::EventHandling::postEvent(const Event& e)
{
	eventQueue.push(e);
}