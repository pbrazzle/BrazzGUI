#ifndef WIN32_CONTROL_HANDLING
#define WIN32_CONTROL_HANDLING

#include "Color.hpp"
#include "ControlHandling/ControlHandling.hpp"

#include <iostream>
#include <windows.h>

namespace BrazzGUI::ControlHandling {
/**
 * Win32 specific OSData for each Control
 */
class Win32Data : public ControlOSData {
    private:
    HWND handle;               // HWND for the Control
    WNDPROC defaultWindowProc; // Default window procedure for the Control
    ControlID id;              // ID for the Control
    HBRUSH backgroundBrush;    // Brush to draw the Control background
    Color backgroundColor;     // Background color for the Control
    Color textColor;           // Text color for the Control

    public:
    /**
     * Creates a new Win32Data object
     */
    Win32Data(const ControlID i, const HWND h,
              const WNDPROC defProc = &DefWindowProc) :
        id(i),
        handle(h),
        defaultWindowProc(defProc),
        backgroundColor{255, 255, 255},
        textColor{0, 0, 0} {
        backgroundBrush = CreateSolidBrush(
            RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
    }

    /**
     * Creates a new Win32Data object
     */
    Win32Data(const Win32Data& other) :
        id(other.id),
        handle(other.handle),
        defaultWindowProc(other.defaultWindowProc),
        backgroundColor(other.backgroundColor),
        textColor{0, 0, 0} {
        backgroundBrush = CreateSolidBrush(
            RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
    }

    /**
     * Assignment operator for Win32Data objects
     * Creates a new brush for the assignee
     */
    Win32Data& operator=(const Win32Data& other) {
        id = other.id;
        handle = other.handle;
        defaultWindowProc = other.defaultWindowProc;
        backgroundColor = other.backgroundColor;
        backgroundBrush = CreateSolidBrush(
            RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
        textColor = other.textColor;
    }

    /**
     * Destructor
     * Frees the background brush
     */
    ~Win32Data() { DeleteObject(backgroundBrush); }

    /**
     * Gets the handle for the Control
     *
     * @return Handle for the Control
     */
    HWND getHandle() const { return handle; }

    /**
     * Gets the ControlID for the Control
     *
     * @return ID for the Control
     */
    ControlID getID() const { return id; }

    /**
     * Sends a message to the default window procedure for the Control
     *
     * @param handle Handle for the Control
     * @param msg Win32 message code
     * @param wp Win32 message data
     * @param lp Win32 message data
     * @return Result of handling the message, 0 means the message was handled
     */
    LRESULT callDefaultWindowProc(HWND handle, UINT msg, WPARAM wp,
                                  LPARAM lp) const {
        return CallWindowProc(defaultWindowProc, handle, msg, wp, lp);
    }

    /**
     * Sets the background color for the Control
     *
     * @param c New background color
     */
    void setBackgroundColor(const Color c) {
        backgroundColor = c;
        DeleteObject(backgroundBrush);
        backgroundBrush = CreateSolidBrush(
            RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
    }

    /**
     * Sets the text color for the Control
     *
     * @param c New text color
     */
    void setTextColor(const Color c) { textColor = c; }

    /**
     * Gets the background brush for the Control
     *
     * @return Background brush for the Control
     */
    HBRUSH getBackgroundBrush() const { return backgroundBrush; }

    /**
     * Gets the background color for the Control
     *
     * @return Background color for the Control
     */
    Color getBackgroundColor() const { return backgroundColor; }

    /**
     * Gets the text color for the Control
     *
     * @return Text color for the Control
     */
    Color getTextColor() const { return textColor; }
};

HWND getHandleFromID(const ControlID& id);

} // namespace BrazzGUI::ControlHandling

#endif