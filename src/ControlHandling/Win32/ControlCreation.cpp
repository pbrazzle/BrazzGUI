#include "ControlHandling/ControlCreation.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"

#include "EventHandling/EventSlotting.hpp"
#include "EventHandling/EventMaker.hpp"

#include <windows.h>
#include <windowsx.h>
#include <map>
#include <memory>
#include <exception>
#include <system_error>
#include <iostream>

#ifndef UNICODE
#define UNICODE
#endif

using namespace BrazzGUI;

static int nextID = 0;

extern LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

std::map<ControlID, std::unique_ptr<ControlHandling::ControlOSData>> idMap;
const ControlHandling::Win32Data defaultData(-1, 0);
std::vector<std::unique_ptr<ControlHandling::ControlOSData>> topWindowData;

const ControlHandling::ControlOSData& ControlHandling::getDataFromID(const ControlID& id)
{
	if (!idMap.count(id)) return defaultData;
	return *idMap.at(id);
}

const wchar_t* to_wchar(const std::string& s)
{
    auto wstring = std::wstring(s.begin(), s.end());
    return wstring.c_str();
}

HWND createChildWindow(const std::string& className, const std::string& defaultText, DWORD style)
{
    if (topWindowData.size() == 0) throw std::logic_error("Cannot create a child control without top-level window");
	
	auto parentHandle = static_cast<ControlHandling::Win32Data*>(topWindowData[0].get())->getHandle();
	HWND hwnd = CreateWindowEx(
		0,
        className.c_str(),                     // Window class
        defaultText.c_str(),    // Window text
        style,            // Window style
        // position and size
        0, 0, 10, 10,
        parentHandle,       // Parent window    
        reinterpret_cast<HMENU>(nextID),       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL
        );
		
	if (hwnd == NULL) throw std::system_error(std::error_code(GetLastError(), std::system_category()), "createChildWindow");

	auto prevProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&BrazzGUIWndProc)));

	ControlID id = { nextID };
	idMap[id] = std::make_unique<ControlHandling::Win32Data>(id, hwnd, prevProc);

	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(idMap[id].get()));

	return hwnd;
}

HWND createWindow()
{
    WNDCLASS wc = { };

    wc.lpfnWndProc   = BrazzGUIWndProc;
    wc.hInstance     = GetModuleHandle(NULL);
    wc.lpszClassName = "BrazzGUI Window";

    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        "BrazzGUI Window",                     // Window class
        "Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
        );
		
	if (hwnd == NULL) throw std::system_error(std::error_code(GetLastError(), std::system_category()), "createWindow");

	ControlID id{ nextID };
	idMap[id] = std::make_unique<ControlHandling::Win32Data>(id, hwnd);

	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(idMap[id].get()));

	topWindowData.emplace_back(std::make_unique<ControlHandling::Win32Data>(id, hwnd));
	return hwnd;
}

const DWORD defaultStyle = WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS;

HWND createButton()
{
    return createChildWindow("BUTTON", "Button", defaultStyle | BS_DEFPUSHBUTTON);
}

HWND createTextbox()
{
    return createChildWindow("EDIT", "", defaultStyle | ES_LEFT | WS_BORDER);
}

HWND createCheckbox()
{
	// Checkbox changes check on click
	EventHandling::connect(Event(nextID, EventType::LEFT_CLICK_DOWN), [](const Event& e) 
	{ 
		auto id = e.getControl();
		auto osData = static_cast<const ControlHandling::Win32Data&>(ControlHandling::getDataFromID(id));
		Button_SetCheck(osData.getHandle(), !Button_GetCheck(osData.getHandle()));
		EventHandling::postEvent(Event(id, EventType::CHECK_CHANGED));
	});
		
    return createChildWindow("BUTTON", "Button", defaultStyle | BS_CHECKBOX);
}

HWND createLabel()
{
    return createChildWindow("STATIC", "Label", defaultStyle | SS_CENTER | SS_NOTIFY);
}

HWND createRadioButton()
{
    return createChildWindow("BUTTON", "Button", defaultStyle | BS_RADIOBUTTON);
}

HWND createTextArea() 
{ 
    return createChildWindow("EDIT", "TextArea", defaultStyle | ES_LEFT | ES_MULTILINE | ES_WANTRETURN);
}

HWND createDrawPane() 
{ 
    //TODO give this the right class and style
    return createChildWindow("BUTTON", "Group", defaultStyle | WS_GROUP | BS_GROUPBOX);
}

HWND createRadioButtonGroup() 
{ 
    return createChildWindow("BUTTON", "Group", defaultStyle | WS_GROUP | BS_GROUPBOX);
}

HWND createComboBox() 
{ 
    return createChildWindow("COMBOBOX", "Combo", defaultStyle | CBS_DROPDOWNLIST | CBS_NOINTEGRALHEIGHT | CBS_HASSTRINGS);
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
		case ControlType::Textbox:
			hwnd = createTextbox();
			break;
		case ControlType::Checkbox:
			hwnd = createCheckbox();
			break;
		case ControlType::RadioButton:
			hwnd = createRadioButton();
			break;
		case ControlType::Label:
			hwnd = createLabel();
			break;
		case ControlType::TextArea:
			hwnd = createTextArea();
			break;
		case ControlType::DrawPane:
			hwnd = createDrawPane();
			break;
		case ControlType::RadioButtonGroup:
			hwnd = createRadioButtonGroup();
			break;
		case ControlType::ComboBox:
			hwnd = createComboBox();
			break;
	}
		
	ControlID id{ nextID };
	nextID++;
	return id;
}

const std::vector<std::unique_ptr<ControlHandling::ControlOSData>>& ControlHandling::getTopWindows()
{
	return topWindowData;
}