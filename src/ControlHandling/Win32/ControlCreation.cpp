#include "ControlHandling/ControlCreation.hpp"

#include "ControlHandling/ControlStyling.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"
#include "EventHandling/EventMaker.hpp"
#include "EventHandling/EventSlotting.hpp"

#include <CommCtrl.h>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <system_error>
#include <windows.h>
#include <windowsx.h>

#ifndef UNICODE
#define UNICODE
#endif

using namespace BrazzGUI;

extern LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                        LPARAM lParam);

std::map<ControlID, std::unique_ptr<ControlHandling::ControlOSData>> idMap;
ControlHandling::Win32Data defaultData(-1, 0);
std::vector<std::unique_ptr<ControlHandling::ControlOSData>> topWindowData;

ControlHandling::ControlOSData&
ControlHandling::getDataFromID(const ControlID& id) {
    if (!idMap.count(id)) return defaultData;
    return *idMap[id];
}

const wchar_t* to_wchar(const std::string& s) {
    auto wstring = std::wstring(s.begin(), s.end());
    return wstring.c_str();
}

HWND createChildWindow(const std::string& className,
                       const std::string& defaultText, DWORD style,
                       ControlID id) {
    if (topWindowData.size() == 0)
        throw std::logic_error(
            "Cannot create a child control without top-level window");

    auto parentHandle =
        static_cast<ControlHandling::Win32Data*>(topWindowData[0].get())
            ->getHandle();
    HWND hwnd = CreateWindowEx(0,
                               className.c_str(),   // Window class
                               defaultText.c_str(), // Window text
                               style,               // Window style
                               // position and size
                               0, 0, 10, 10,
                               parentHandle, // Parent window
                               reinterpret_cast<HMENU>(id.getValue()), // Menu
                               GetModuleHandle(NULL), // Instance handle
                               NULL);

    if (hwnd == NULL)
        throw std::system_error(
            std::error_code(GetLastError(), std::system_category()),
            "createChildWindow");

    auto prevProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(
        hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&BrazzGUIWndProc)));

    // DefWindowProc is the def proc for BrazzGUI
    if (prevProc == reinterpret_cast<WNDPROC>(&BrazzGUIWndProc)) {
        prevProc = reinterpret_cast<WNDPROC>(&DefWindowProc);
    }

    idMap[id] =
        std::make_unique<ControlHandling::Win32Data>(id, hwnd, prevProc);

    SetWindowLongPtr(hwnd, GWLP_USERDATA,
                     reinterpret_cast<LONG_PTR>(idMap[id].get()));

    return hwnd;
}

HWND createWindow(ControlID id) {
    WNDCLASS wc = {};

    wc.lpfnWndProc = BrazzGUIWndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "BrazzGUI Window";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                                     // Optional window styles.
        "BrazzGUI Window",                     // Window class
        "Learn to Program Windows",            // Window text
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,                  // Parent window
        NULL,                  // Menu
        GetModuleHandle(NULL), // Instance handle
        NULL                   // Additional application data
    );

    if (hwnd == NULL)
        throw std::system_error(
            std::error_code(GetLastError(), std::system_category()),
            "createWindow");

    EventHandling::connect(
        Event(id, EventType::LEFT_CLICK_DOWN),
        [](const Event& e) { ControlStyling::takeFocus(e.getControl()); });

    idMap[id] = std::make_unique<ControlHandling::Win32Data>(id, hwnd);

    SetWindowLongPtr(hwnd, GWLP_USERDATA,
                     reinterpret_cast<LONG_PTR>(idMap[id].get()));

    topWindowData.emplace_back(
        std::make_unique<ControlHandling::Win32Data>(id, hwnd));
    return hwnd;
}

const DWORD defaultStyle = WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS;

HWND createButton(ControlID id) {
    return createChildWindow("BUTTON", "Button",
                             defaultStyle | BS_DEFPUSHBUTTON, id);
}

HWND createTextbox(ControlID id) {
    return createChildWindow("EDIT", "", defaultStyle | ES_LEFT | WS_BORDER,
                             id);
}

HWND createCheckbox(ControlID id) {
    EventHandling::connect(
        Event(id, EventType::LEFT_CLICK_DOWN), [](const Event& e) {
            auto id = e.getControl();
            auto osData = static_cast<const ControlHandling::Win32Data&>(
                ControlHandling::getDataFromID(id));
            Button_SetCheck(osData.getHandle(),
                            !Button_GetCheck(osData.getHandle()));
            EventHandling::postEvent(Event(id, EventType::CHECK_CHANGED));
        });

    return createChildWindow("BUTTON", "Button", defaultStyle | BS_CHECKBOX,
                             id);
}

HWND createLabel(ControlID id) {
    return createChildWindow("STATIC", "Label",
                             defaultStyle | SS_CENTER | SS_NOTIFY, id);
}

HWND createRadioButton(ControlID id) {
    return createChildWindow("BUTTON", "Button", defaultStyle | BS_RADIOBUTTON,
                             id);
}

HWND createTextArea(ControlID id) {
    return createChildWindow(
        "EDIT", "TextArea",
        defaultStyle | ES_LEFT | ES_MULTILINE | ES_WANTRETURN, id);
}

HWND createDrawPane(ControlID id) {
    return createChildWindow("BrazzGUI Window", "", WS_CHILD | WS_VISIBLE, id);
}

HWND createRadioButtonGroup(ControlID id) {
    return createChildWindow("BUTTON", "Group",
                             defaultStyle | WS_GROUP | BS_GROUPBOX, id);
}

HWND createComboBox(ControlID id) {
    return createChildWindow("COMBOBOX", "Combo",
                             defaultStyle | CBS_DROPDOWNLIST |
                                 CBS_NOINTEGRALHEIGHT | CBS_HASSTRINGS,
                             id);
}

HWND createPanel(ControlID id) {
    return createChildWindow("BrazzGUI Window", "", WS_CHILD | WS_VISIBLE, id);
}

HWND createTabGroup(ControlID id) {
    return createChildWindow(WC_TABCONTROL, "", defaultStyle, id);
}

ControlID ControlCreation::createControl(const BrazzGUI::ControlType& type) {
    HWND hwnd;
    auto id = ControlID();
    switch (type) {
        case ControlType::Window:
            hwnd = createWindow(id);
            break;
        case ControlType::Button:
            hwnd = createButton(id);
            break;
        case ControlType::Textbox:
            hwnd = createTextbox(id);
            break;
        case ControlType::Checkbox:
            hwnd = createCheckbox(id);
            break;
        case ControlType::RadioButton:
            hwnd = createRadioButton(id);
            break;
        case ControlType::Label:
            hwnd = createLabel(id);
            break;
        case ControlType::TextArea:
            hwnd = createTextArea(id);
            break;
        case ControlType::DrawPane:
            hwnd = createDrawPane(id);
            break;
        case ControlType::RadioButtonGroup:
            hwnd = createRadioButtonGroup(id);
            break;
        case ControlType::ComboBox:
            hwnd = createComboBox(id);
            break;
        case ControlType::Panel:
            hwnd = createPanel(id);
            break;
        case ControlType::TabGroup:
            hwnd = createTabGroup(id);
            break;
    }

    return id;
}

const std::vector<std::unique_ptr<ControlHandling::ControlOSData>>&
ControlHandling::getTopWindows() {
    return topWindowData;
}