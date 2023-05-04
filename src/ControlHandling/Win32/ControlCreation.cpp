#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"

#include <windows.h>
#include <map>
#include <memory>

using namespace BrazzGUI;

static int nextID = 0;

extern LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

std::map<ControlID, std::unique_ptr<ControlHandling::ControlOSData>> idMap;

const ControlHandling::ControlOSData& ControlHandling::getDataFromID(const ControlID& id)
{
	return *idMap.at(id);
}

ControlID ControlCreation::createControl(const ControlCreation::ControlType& type)
{
	const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = BrazzGUIWndProc;
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpszClassName = (LPCSTR) CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        (LPCSTR) CLASS_NAME,                     // Window class
        (LPCSTR) L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
        );
		
	ControlID id = { nextID };
	idMap[id] = std::make_unique<ControlHandling::Win32Data>(hwnd);
	nextID++;
	return id;
}