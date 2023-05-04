#include "EventHandling/EventMaker.hpp"
#include "EventHandling/Event.hpp"

#include <windows.h>
#include <queue>

using namespace BrazzGUI::EventHandling;

std::queue<Event> eventQueue;

LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
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
	PostMessage(HWND_BROADCAST, WM_CLOSE, 0, 0);
}