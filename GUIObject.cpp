#include "GUIObject.h"

LRESULT CALLBACK dispatchEvent(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void registerWindowClass()
{
	// Register the window class.
    const LPCSTR CLASS_NAME  = (LPCSTR) "Sample Window Class";
    HINSTANCE hInstance = GetModuleHandle(NULL);
	
	if (GetClassInfoEx(hInstance, CLASS_NAME, NULL)) return;
	
    WNDCLASS wc = { };

    wc.lpfnWndProc   = dispatchEvent;
    wc.hInstance     = hInstance;
    wc.lpszClassName = (LPCSTR) CLASS_NAME;

    RegisterClass(&wc);
}

GUIObject::GUIObject() { }

std::string getWin32Classname(std::string classname)
{
	if (classname == "Window") return "Sample Window Class";
	if (classname == "Button") return "Button";
	return "";
}

DWORD getWin32Style(std::string classname, std::string style)
{
	if (classname == "Window") return WS_OVERLAPPEDWINDOW;
	if (classname == "Button") return WS_VISIBLE | BS_DEFPUSHBUTTON;
	return 0;
}

GUIObject::GUIObject(std::string classname, std::string style)
{
	registerWindowClass();
	
	std::string win32Classname = getWin32Classname(classname);
	DWORD win32Style = getWin32Style(classname, style);
	
	hwnd = CreateWindowEx(
        0,                              			// Optional window styles.
        win32Classname.c_str(),           // Window class
        (LPCSTR) "Learn to Program Windows",    	// Window text
        win32Style,            			// Window style

        // Size and position
        100, 100, 100, 100,

        NULL,       // Parent window    
        NULL,       // Menu
        NULL,  		// Instance handle
        NULL        // Additional application data
        );
		
	MessageBox(NULL, win32Classname.c_str(), std::to_string(GetLastError()).c_str(), NULL);
}

void GUIObject::show()
{
	ShowWindow(hwnd, SW_SHOWNORMAL);
}

HWND GUIObject::getHandle()
{
	return hwnd;
}