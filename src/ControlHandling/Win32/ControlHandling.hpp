#ifndef WIN32_CONTROL_HANDLING
#define WIN32_CONTROL_HANDLING

#include "ControlHandling/ControlHandling.hpp"
#include "Color.hpp"
#include <windows.h>
#include <iostream>

namespace BrazzGUI::ControlHandling
{
	class Win32Data : public ControlOSData
	{
		private:
			HWND handle;
			WNDPROC defaultWindowProc;
			ControlID id;
			HBRUSH backgroundBrush;
			Color backgroundColor;

		public:
			Win32Data(const ControlID i, const HWND h, const WNDPROC defProc = &DefWindowProc) 
			: id(i), handle(h), defaultWindowProc(defProc), backgroundColor{255, 255, 255} { 
				backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
			}

			Win32Data(const Win32Data& other)
			: id(other.id), handle(other.handle), 
			defaultWindowProc(other.defaultWindowProc), backgroundColor(other.backgroundColor) {
				backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
			}

			Win32Data& operator=(const Win32Data& other) {
				id = other.id;
				handle = other.handle;
				defaultWindowProc = other.defaultWindowProc;
				backgroundColor = other.backgroundColor;
				backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
			}

			~Win32Data() {
				DeleteObject(backgroundBrush);
			}
		
			HWND getHandle() const { return handle; }

			ControlID getID() const { return id; }

			LRESULT callDefaultWindowProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp) const{
				return CallWindowProc(defaultWindowProc, handle, msg, wp, lp);
			}

			void setBackgroundColor(const Color c) {
				backgroundColor = c;
				DeleteObject(backgroundBrush);
				backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
			}

			HBRUSH getBackgroundBrush() const {
				return backgroundBrush;
			}

			Color getBackgroundColor() const {
				return backgroundColor;
			}
	};
}

#endif