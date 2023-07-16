#include "EventHandling/EventMaker.hpp"
#include "ControlHandling/Win32/ControlHandling.hpp"
#include "Event.hpp"
#include "EventHandling/EventSlotting.hpp"

#include <iostream>
#include <queue>
#include <windows.h>

using namespace BrazzGUI::EventHandling;
using namespace BrazzGUI;

std::queue<Event> eventQueue;

LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                 LPARAM lParam) {
    auto osData = reinterpret_cast<const ControlHandling::Win32Data *>(
        GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (!osData)
        return DefWindowProc(hwnd, uMsg, wParam, lParam);

    auto id = osData->getID();

    switch (uMsg) {
    case WM_LBUTTONDOWN:
        eventQueue.push(Event(id, EventType::LEFT_CLICK_DOWN));
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED || HIWORD(wParam) == STN_CLICKED ||
            HIWORD(wParam) == EN_SETFOCUS) {
            auto idVal = static_cast<int>(LOWORD(wParam));
            // eventQueue.push(Event(idVal, EventType::LEFT_CLICK_DOWN));
        } else if (HIWORD(wParam) == EN_CHANGE) {
            auto idVal = static_cast<int>(LOWORD(wParam));
            eventQueue.push(Event(idVal, EventType::TEXT_CHANGED));
        }
        break;
    case WM_PAINT:
        EventHandling::runSlots(Event(id, EventType::PAINT));
        break;
    case WM_ERASEBKGND: {
        EventHandling::runSlots(Event(id, EventType::DRAW_BACKGROUND));
        break;
    }
    case WM_SIZE: {
        EventHandling::runSlots(Event(id, EventType::RESIZED));
        break;
    }
    case WM_CTLCOLORBTN:
    case WM_CTLCOLOREDIT:
    case WM_CTLCOLORLISTBOX:
    case WM_CTLCOLORSTATIC: {
        hwnd = reinterpret_cast<HWND>(lParam);

        // Get ComboBox parent from ListBox
        if (uMsg == WM_CTLCOLORLISTBOX)
            hwnd = GetParent(hwnd);

        osData = reinterpret_cast<const ControlHandling::Win32Data *>(
            GetWindowLongPtr(hwnd, GWLP_USERDATA));

        // ComboBox has NULL osData somehow???
        if (osData == NULL)
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        auto bgColor = osData->getBackgroundColor();
        auto textColor = osData->getTextColor();
        auto hdc = reinterpret_cast<HDC>(wParam);
        SetBkColor(hdc, RGB(bgColor.r, bgColor.g, bgColor.b));
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(textColor.r, textColor.g, textColor.b));

        auto color = GetBkColor(hdc);

        return reinterpret_cast<INT_PTR>(osData->getBackgroundBrush());
    }
    }
    return osData->callDefaultWindowProc(hwnd, uMsg, wParam, lParam);
}

bool handleMessage() {
    MSG msg = {};
    BOOL result = GetMessage(&msg, NULL, 0, 0);
    if (result == 0)
        return false;

    // TODO Check for error
    // if (result == -1) throw -1;

    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return true;
}

Event BrazzGUI::EventHandling::getNextEvent() {
    while (eventQueue.empty()) {
        if (!handleMessage())
            return Event(EventType::QUIT);
    }
    auto next = eventQueue.front();
    eventQueue.pop();
    return next;
}

void BrazzGUI::EventHandling::postStopEvent() {
    auto &topWindowData = BrazzGUI::ControlHandling::getTopWindows();
    for (int i = 0; i < topWindowData.size(); i++) {
        auto win32Data = static_cast<const ControlHandling::Win32Data *>(
            topWindowData[i].get());
        auto handle = win32Data->getHandle();
        PostMessage(handle, WM_CLOSE, 0, 0);
    }
}

void BrazzGUI::EventHandling::postEvent(const Event &e) { eventQueue.push(e); }