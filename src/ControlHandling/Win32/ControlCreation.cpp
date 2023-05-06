#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"

#include <windows.h>
#include <map>
#include <memory>
#include <exception>
#include <system_error>

#ifndef UNICODE
#define UNICODE
#endif

using namespace BrazzGUI;

static int nextID = 0;

extern LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

std::map<ControlID, std::unique_ptr<ControlHandling::ControlOSData>> idMap;
std::vector<std::unique_ptr<ControlHandling::ControlOSData>> topWindowData;

const ControlHandling::ControlOSData& ControlHandling::getDataFromID(const ControlID& id)
{
	return *idMap.at(id);
}

HWND createWindow()
{
	const CHAR CLASS_NAME[]  = "Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = BrazzGUIWndProc;
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        reinterpret_cast<void*>((uintptr_t)nextID)        // Additional application data
        );
		
	if (hwnd == NULL) throw std::system_error(std::error_code(GetLastError(), std::system_category()), "createWindow");
		
	topWindowData.emplace_back(std::make_unique<ControlHandling::Win32Data>(hwnd));
	return hwnd;
}

HWND createButton()
{
	if (topWindowData.size() == 0) throw std::logic_error("Cannot create a child control without top-level window");
	
	auto parentHandle = static_cast<ControlHandling::Win32Data*>(topWindowData[0].get())->getHandle();
	HWND hwnd = CreateWindowEx(
		0,
        "BUTTON",                     // Window class
        "Button",    // Window text
        WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | BS_DEFPUSHBUTTON,            // Window style
        // position and size
        0, 0, 10, 10,
        parentHandle,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        reinterpret_cast<void*>((uintptr_t)nextID)        // Additional application data
        );
		
	if (hwnd == NULL) throw std::system_error(std::error_code(GetLastError(), std::system_category()), "createButton");
		
	return hwnd;
}

ControlID ControlCreation::createControl(const ControlCreation::ControlType& type)
{
	HWND hwnd;
	switch(type)
	{
		case ControlType::Window:
			hwnd = createWindow();
			break;
		case ControlType::Button:
			hwnd = createButton();
			break;
	}
		
	ControlID id = { nextID };
	idMap[id] = std::make_unique<ControlHandling::Win32Data>(hwnd);
	nextID++;
	return id;
}

const std::vector<std::unique_ptr<ControlHandling::ControlOSData>>& ControlHandling::getTopWindows()
{
	return topWindowData;
}