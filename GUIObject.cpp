#include "GUIObject.h"

void registerWindowClass()
{
	// Register the window class.
    const LPCSTR CLASS_NAME  = (LPCSTR) L"Sample Window Class";
    HINSTANCE hInstance = GetModuleHandle(NULL);
	
    WNDCLASS wc = { };

    wc.lpfnWndProc   = dispatchEvent;
    wc.hInstance     = hInstance;
    wc.lpszClassName = (LPCSTR) CLASS_NAME;

	if (GetClassInfoEx(hInstance, CLASS_NAME, (LPWNDCLASSEXA) &wc)) return;
    RegisterClass(&wc);
}

GUIObject::GUIObject() { }

GUIObject::GUIObject(std::string classname, std::string style, EventHandler* handler)
{
	registerWindowClass();
	
	hwnd = CreateWindowEx(
        0,                              			// Optional window styles.
        (LPCSTR) L"Sample Window Class",           // Window class
        (LPCSTR) "Learn to Program Windows",    	// Window text
        WS_OVERLAPPEDWINDOW,            			// Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        NULL,  // Instance handle
        handler        // Additional application data
        );
}

void GUIObject::show()
{
	ShowWindow(hwnd, SW_SHOWNORMAL);
}