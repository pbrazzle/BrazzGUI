//Using BrazzGUI classes to create a Window

#include <windows.h>

#include "Window.h"

LRESULT CALLBACK dispatchEvent(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	EventHandler* handler = (EventHandler*) GetWindowLongPtr(hwnd, GWLP_USERDATA);
	return handler->handleEvent(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = dispatchEvent;
    wc.hInstance     = hInstance;
    wc.lpszClassName = (LPCSTR) CLASS_NAME;

    RegisterClass(&wc);
	
	Window myWindow;
	myWindow.show();
	
	MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
	
	return 0;
}