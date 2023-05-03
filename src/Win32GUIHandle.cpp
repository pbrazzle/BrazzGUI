#include "Win32GUIHandle.h"

LRESULT CALLBACK TODOwndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void registerWindowClass()
{
	// Register the window class.
    const LPCSTR CLASS_NAME  = (LPCSTR) "Sample Window Class";
    HINSTANCE hInstance = GetModuleHandle(NULL);
	
	if (GetClassInfoEx(hInstance, CLASS_NAME, NULL)) return;
	
    WNDCLASS wc = { };

    wc.lpfnWndProc   = TODOwndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = (LPCSTR) CLASS_NAME;

    RegisterClass(&wc);
}

Win32GUIHandle::Win32GUIHandle()
{
	handle = nullptr;
	
	registerWindowClass();
	
	handle = CreateWindowEx(
        0,                              			// Optional window styles.
        (LPCSTR) "Sample Window Class",           	// Window class
        (LPCSTR) "Sample Window Class",    			// Window text
        WS_OVERLAPPEDWINDOW,            			// Window style

        // Size and position
        100, 100, 100, 100,

        NULL,       // Parent window    
        NULL,       // Menu
        NULL,  		// Instance handle
        NULL        // Additional application data
        );
}
	
void Win32GUIHandle::setVisible(bool)
{
	ShowWindow(handle, SW_SHOWNORMAL);
}

void Win32GUIHandle::setWidth(int)
{
	
}

void Win32GUIHandle::setHeight(int)
{
	
}

void Win32GUIHandle::setX(int)
{
	
}

void Win32GUIHandle::setY(int)
{
	
}

HWND Win32GUIHandle::getHandle() const
{
	return handle;
}

void Win32GUIHandle::setParent(const GUIHandle&)
{
	
}