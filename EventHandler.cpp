#include "EventHandler.h"

#include <windows.h>

LRESULT CALLBACK dispatchEvent(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	EventHandler* handler = (EventHandler*) GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if (handler == NULL) return DefWindowProc(hwnd, uMsg, wParam, lParam);
	return handler->handleEvent(hwnd, uMsg, wParam, lParam);
}

EventHandler::EventHandler() { }

void EventHandler::attachGUIObject(GUIObject obj)
{
	HWND handle = obj.getHandle();
	
	SetWindowLongPtr(handle, GWLP_USERDATA, (LONG_PTR) this);
}

LRESULT EventHandler::handleEvent(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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