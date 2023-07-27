#include "EventHandling/EventMaker.hpp"

#include "ControlHandling/Win32/ControlHandling.hpp"
#include "Event.hpp"
#include "EventHandling/EventSlotting.hpp"
#include "Handlers/Win32/Win32MenuHandler.hpp"

#include <CommCtrl.h>
#include <exception>
#include <iostream>
#include <queue>
#include <windows.h>

using namespace BrazzGUI::EventHandling;
using namespace BrazzGUI;

std::queue<Event> eventQueue;

LRESULT CALLBACK BrazzGUIWndProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                 LPARAM lParam) {
    auto osData = reinterpret_cast<const ControlHandling::Win32Data*>(
        GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (!osData) return DefWindowProc(hwnd, uMsg, wParam, lParam);

    auto id = osData->getID();

    switch (uMsg) {
        case WM_MOUSEWHEEL: {
            auto direction = static_cast<short int>(HIWORD(wParam));
            EventType type;
            if (direction > 0) type = EventType::SCROLL_UP;
            else type = EventType::SCROLL_DOWN;
            eventQueue.push(Event(id, type));

            // Top-level windows finish processing
            if (GetParent(hwnd) == NULL) return 0;
        } break;
        case WM_KEYDOWN:
            eventQueue.push(Event(
                id, EventType::KEY_DOWN,
                std::make_unique<KeyEventData>(static_cast<EventKey>(wParam))));
            break;
        case WM_RBUTTONDOWN:
        case WM_RBUTTONDBLCLK:
            eventQueue.push(Event(id, EventType::RIGHT_CLICK_DOWN));
            break;
        case WM_MENUCOMMAND: {
            auto clickedID = BrazzGUI::Handlers::Win32::Win32MenuHandler::
                getChildIDFromHandle(reinterpret_cast<HMENU>(lParam),
                                     static_cast<int>(wParam));
            eventQueue.push(Event(clickedID, EventType::LEFT_CLICK_DOWN));
            break;
        }
        case WM_LBUTTONDOWN:
            eventQueue.push(Event(id, EventType::LEFT_CLICK_DOWN));
            break;
        case WM_LBUTTONDBLCLK:
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
        case WM_NOTIFY: {
            auto notificationData = reinterpret_cast<LPNMHDR>(lParam);
            auto idVal = ControlID(notificationData->idFrom);
            switch (notificationData->code) {
                case TCN_SELCHANGE:
                    eventQueue.push(Event(idVal, EventType::TAB_CHANGED));
                    break;
            }
        }
        case WM_PAINT:
            EventHandling::runSlots(Event(id, EventType::PAINT));
            break;
        case WM_ERASEBKGND: {
            // std::cout << "Control " << id.getValue()
            //           << " drawing background...\n";
            EventHandling::runSlots(Event(id, EventType::DRAW_BACKGROUND));

            auto hdc = reinterpret_cast<HDC>(wParam);
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, (HBRUSH) GetStockObject(WHITE_BRUSH));
            return 1;
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
            // std::cout << "CTLCOLOR\n";
            hwnd = reinterpret_cast<HWND>(lParam);

            // Get ComboBox parent from ListBox
            if (uMsg == WM_CTLCOLORLISTBOX) hwnd = GetParent(hwnd);

            osData = reinterpret_cast<const ControlHandling::Win32Data*>(
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
    if (result == 0) return false;

    if (result == -1) throw std::logic_error("Failed to retrieve next Event");

    TranslateMessage(&msg);
    DispatchMessage(&msg);
    return true;
}

Event BrazzGUI::EventHandling::getNextEvent() {
    while (eventQueue.empty()) {
        if (!handleMessage()) return Event(EventType::QUIT);
    }
    auto next = eventQueue.front();
    eventQueue.pop();
    return next;
}

void BrazzGUI::EventHandling::postStopEvent() {
    auto& topWindowData = BrazzGUI::ControlHandling::getTopWindows();
    for (int i = 0; i < topWindowData.size(); i++) {
        auto win32Data = static_cast<const ControlHandling::Win32Data*>(
            topWindowData[i].get());
        auto handle = win32Data->getHandle();
        PostMessage(handle, WM_CLOSE, 0, 0);
    }
}

void BrazzGUI::EventHandling::postEvent(const Event& e) { eventQueue.push(e); }