#include "GUIObject.h"

GUIObject::GUIObject() { }

GUIObject::GUIObject(std::string classname, std::string style, EventHandler* handler)
{
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