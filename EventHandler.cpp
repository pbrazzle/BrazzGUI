#include "EventHandler.h"

LRESULT CALLBACK dispatchEvent(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	EventHandler* handler = (EventHandler*) GetWindowLongPtr(hwnd, GWLP_USERDATA);
	return handler->handleEvent(hwnd, uMsg, wParam, lParam);
}

EventHandler::EventHandler() { }

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