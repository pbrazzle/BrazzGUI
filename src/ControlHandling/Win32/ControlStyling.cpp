#include "ControlHandling/ControlStyling.hpp"

#include "ControlHandling/Win32/ControlHandling.hpp"
#include "ControlHandling/Win32/FontHandler.hpp"
#include "EventHandling/EventMaker.hpp"

#include <CommCtrl.h>
#include <iostream>
#include <windows.h>
#include <windowsx.h>

using namespace BrazzGUI;
using namespace BrazzGUI::ControlHandling;

HWND ControlHandling::getHandleFromID(const ControlID& id) {
    auto osData = static_cast<const ControlHandling::Win32Data&>(
        ControlHandling::getDataFromID(id));
    return osData.getHandle();
}

void ControlStyling::setCheck(const ControlID& id, const bool& c) {
    Button_SetCheck(getHandleFromID(id), c);
    EventHandling::postEvent(Event(id, EventType::CHECK_CHANGED));
}

bool ControlStyling::isChecked(const ControlID& id) {
    return Button_GetCheck(getHandleFromID(id));
}

void ControlStyling::show(const ControlID& id) {
    auto handle = getHandleFromID(id);
    ShowWindow(handle, SW_NORMAL);
}

void ControlStyling::setX(const ControlID& id, const int& x) {
    auto handle = getHandleFromID(id);
    auto parent = GetParent(handle);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    POINT client = {windowPos.left, windowPos.top};
    if (handle != parent) ScreenToClient(parent, &client);
    SetWindowPos(handle, NULL, x, client.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void ControlStyling::setY(const ControlID& id, const int& y) {
    auto handle = getHandleFromID(id);
    auto parent = GetParent(handle);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    POINT client = {windowPos.left, windowPos.top};
    if (handle != parent) ScreenToClient(parent, &client);
    SetWindowPos(handle, NULL, client.x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void ControlStyling::setWidth(const ControlID& id, const int& width) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    SetWindowPos(handle, NULL, 0, 0, width, windowPos.bottom - windowPos.top,
                 SWP_NOMOVE | SWP_NOZORDER);
}

void ControlStyling::setHeight(const ControlID& id, const int& height) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    SetWindowPos(handle, NULL, 0, 0, windowPos.right - windowPos.left, height,
                 SWP_NOMOVE | SWP_NOZORDER);
}

void ControlStyling::setText(const ControlID& id, const std::string& text) {
    auto handle = getHandleFromID(id);
    SetWindowText(handle, text.c_str());
    EventHandling::postEvent(Event(id, EventType::TEXT_CHANGED));
}

void ControlStyling::setFont(const ControlID& id, const Font& font) {
    HFONT fontHandle = FontHandler::getFontHandle(font);
    auto handle = getHandleFromID(id);

    SendMessage(handle, WM_SETFONT, (WPARAM) fontHandle, (LPARAM) TRUE);
}

int ControlStyling::getX(const ControlID& id) {
    auto handle = getHandleFromID(id);
    auto parent = GetParent(handle);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    POINT client = {windowPos.left, windowPos.top};
    if (handle != parent) ScreenToClient(parent, &client);
    return client.x;
}

int ControlStyling::getY(const ControlID& id) {
    auto handle = getHandleFromID(id);
    auto parent = GetParent(handle);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    POINT client = {windowPos.left, windowPos.top};
    if (handle != parent) ScreenToClient(parent, &client);
    return client.y;
}

int ControlStyling::getComboBoxHeight(const ControlID& id) {
    auto handle = getHandleFromID(id);
    RECT comboBoxRect;
    SendMessage(handle, CB_GETDROPPEDCONTROLRECT, NULL, (LPARAM) &comboBoxRect);
    return comboBoxRect.bottom - comboBoxRect.top;
}

int ControlStyling::getWidth(const ControlID& id) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    return windowPos.right - windowPos.left;
}

int ControlStyling::getHeight(const ControlID& id) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetWindowRect(handle, &windowPos);
    return windowPos.bottom - windowPos.top;
}

int ControlStyling::getClientWidth(const ControlID id) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetClientRect(handle, &windowPos);
    return windowPos.right - windowPos.left;
}

int ControlStyling::getClientHeight(const ControlID id) {
    auto handle = getHandleFromID(id);
    RECT windowPos;
    GetClientRect(handle, &windowPos);
    return windowPos.bottom - windowPos.top;
}

std::string ControlStyling::getText(const ControlID& id) {
    auto handle = getHandleFromID(id);
    auto textLength = GetWindowTextLength(handle);
    char* textBuf = new char[textLength + 1];
    GetWindowText(handle, textBuf, textLength + 1);
    std::string textStr(textBuf);
    delete[] textBuf;
    return textStr;
}

void ControlStyling::setChild(const ControlID& parent, const ControlID& child) {
    auto parentHandle = getHandleFromID(parent);
    auto childHandle = getHandleFromID(child);
    auto result = SetParent(childHandle, parentHandle);
    SetWindowPos(childHandle, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
    if (result == NULL) std::cout << "SetParent failed!\n";
}

void ControlStyling::drawBackground(const ControlID id, const Color color) {
    auto handle = getHandleFromID(id);
    auto hdc = GetDC(handle);
    RECT clientRect;
    GetClientRect(handle, &clientRect);
    auto brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
    FillRect(hdc, &clientRect, brush);
    DeleteObject(brush);
    ReleaseDC(handle, hdc);
}

void ControlStyling::setBackgroundColor(const ControlID id, const Color color) {
    std::cout << "Control " << id.getValue() << " setting background color\n";
    auto& osData = getDataFromID(id);
    osData.setBackgroundColor(color);
}

void ControlStyling::drawText(const ControlID id, const Color color) {
    auto handle = getHandleFromID(id);
    auto dc = GetDC(handle);
    SetTextColor(dc, RGB(color.r, color.g, color.b));
    ReleaseDC(handle, dc);
}

void ControlStyling::setTextColor(const ControlID id, const Color color) {
    auto& osData = getDataFromID(id);
    osData.setTextColor(color);
}

void ControlStyling::addTab(const ControlID id, std::string& tabName) {
    auto handle = getHandleFromID(id);

    // Get number of items
    auto tabCount = TabCtrl_GetItemCount(handle);

    // Insert a new tab
    TCITEM newTab = {0};
    newTab.mask = TCIF_TEXT;
    newTab.pszText = reinterpret_cast<LPSTR>(tabName.data());
    newTab.iImage = -1;

    TabCtrl_InsertItem(handle, tabCount, &newTab);
}

int ControlStyling::getTabAreaWidth(const ControlID id) {
    RECT tabRect;
    auto handle = getHandleFromID(id);
    auto parentHandle = GetParent(handle);
    GetClientRect(parentHandle, &tabRect);

    TabCtrl_AdjustRect(handle, FALSE, &tabRect);

    return tabRect.right - tabRect.left;
}

int ControlStyling::getTabAreaHeight(const ControlID id) {
    RECT tabRect;
    auto handle = getHandleFromID(id);
    auto parentHandle = GetParent(handle);
    GetClientRect(parentHandle, &tabRect);

    TabCtrl_AdjustRect(handle, FALSE, &tabRect);

    return tabRect.bottom - tabRect.top;
}

int ControlStyling::getTabAreaX(const ControlID id) {
    RECT tabRect;
    auto handle = getHandleFromID(id);
    auto parentHandle = GetParent(handle);
    GetClientRect(parentHandle, &tabRect);

    TabCtrl_AdjustRect(handle, FALSE, &tabRect);

    return tabRect.left;
}

int ControlStyling::getTabAreaY(const ControlID id) {
    RECT tabRect;
    auto handle = getHandleFromID(id);
    auto parentHandle = GetParent(handle);
    GetClientRect(parentHandle, &tabRect);

    TabCtrl_AdjustRect(handle, FALSE, &tabRect);

    return tabRect.top;
}

int ControlStyling::getSelectedTabIndex(const ControlID id) {
    auto handle = getHandleFromID(id);
    return TabCtrl_GetCurSel(handle);
}

void ControlStyling::setVisible(const ControlID id, const bool visible) {
    auto handle = getHandleFromID(id);
    if (visible) ShowWindow(handle, SW_SHOW);
    else ShowWindow(handle, SW_HIDE);
}

void ControlStyling::takeFocus(const ControlID id) {
    auto handle = getHandleFromID(id);
    SetFocus(handle);
}

/**Drawing functions**/

Color getDrawColor(const ControlID id) {
    auto osData = static_cast<const ControlHandling::Win32Data&>(
        ControlHandling::getDataFromID(id));
    return osData.getDrawColor();
}

void ControlStyling::setDrawColor(const ControlID id, const Color c) {
    auto& osData = static_cast<ControlHandling::Win32Data&>(
        ControlHandling::getDataFromID(id));
    osData.setDrawColor(c);
    auto c2 = osData.getDrawColor();
}

void ControlStyling::drawPixel(const ControlID id, int x, int y) {
    auto handle = getHandleFromID(id);
    PAINTSTRUCT ps;
    auto hdc = BeginPaint(handle, &ps);

    auto drawColor = getDrawColor(id);

    SetPixel(hdc, x, y, RGB(drawColor.r, drawColor.g, drawColor.b));

    EndPaint(handle, &ps);
}

void ControlStyling::drawLine(const ControlID id, int x1, int y1, int x2,
                              int y2) {
    auto handle = getHandleFromID(id);
    PAINTSTRUCT ps;
    auto hdc = BeginPaint(handle, &ps);

    auto drawColor = getDrawColor(id);
    auto pen =
        CreatePen(PS_SOLID, 2, RGB(drawColor.r, drawColor.g, drawColor.b));
    SelectObject(hdc, pen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    DeleteObject(pen);

    EndPaint(handle, &ps);
}

void ControlStyling::drawRect(const ControlID id, int x1, int y1, int x2,
                              int y2) {
    auto handle = getHandleFromID(id);
    PAINTSTRUCT ps;
    auto hdc = BeginPaint(handle, &ps);

    auto drawColor = getDrawColor(id);
    auto pen =
        CreatePen(PS_SOLID, 5, RGB(drawColor.r, drawColor.g, drawColor.b));
    SelectObject(hdc, pen);

    Rectangle(hdc, x1, y1, x2, y2);

    DeleteObject(pen);

    EndPaint(handle, &ps);
}

void ControlStyling::drawCircle(const ControlID id, int x1, int y1,
                                double radius) {
    auto handle = getHandleFromID(id);
    PAINTSTRUCT ps;
    auto hdc = BeginPaint(handle, &ps);

    auto drawColor = getDrawColor(id);
    auto pen =
        CreatePen(PS_SOLID, 5, RGB(drawColor.r, drawColor.g, drawColor.b));
    SelectObject(hdc, pen);

    // Outlined by pen, filled by brush
    Ellipse(hdc, x1 - radius, y1 - radius, x1 + radius, y1 + radius);

    DeleteObject(pen);

    EndPaint(handle, &ps);
}

void ControlStyling::drawText(const ControlID id, int x1, int y1, int pt,
                              const std::string& text) {
    auto handle = getHandleFromID(id);
    PAINTSTRUCT ps;
    auto hdc = BeginPaint(handle, &ps);

    // Uses selected text color
    TextOut(hdc, x1, y1, text.c_str(), text.size());

    EndPaint(handle, &ps);
}