#ifndef WIN32_CONTROL_HANDLING
#define WIN32_CONTROL_HANDLING

#include "ControlHandling/ControlHandling.hpp"
#include "Color.hpp"
#include <windows.h>
#include <iostream>

namespace BrazzGUI::ControlHandling
{
/**
 * TODO document this class
*/
class Win32Data : public ControlOSData
{
	private:
		HWND handle;
		WNDPROC defaultWindowProc;
		ControlID id;
		HBRUSH backgroundBrush;
		Color backgroundColor;
		Color textColor;

	public:
		/**
 		* TODO document this function
		*/
		Win32Data(const ControlID i, const HWND h, const WNDPROC defProc = &DefWindowProc) 
		: id(i), handle(h), defaultWindowProc(defProc), backgroundColor{255, 255, 255}, textColor{0, 0, 0} { 
			backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
		}

		/**
 		* TODO document this function
		*/
		Win32Data(const Win32Data& other)
		: id(other.id), handle(other.handle), 
		defaultWindowProc(other.defaultWindowProc), backgroundColor(other.backgroundColor), textColor{0, 0, 0} {
			backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
		}

		/**
 		* TODO document this function
		*/
		Win32Data& operator=(const Win32Data& other) {
			id = other.id;
			handle = other.handle;
			defaultWindowProc = other.defaultWindowProc;
			backgroundColor = other.backgroundColor;
			backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
			textColor = other.textColor;
		}

		/**
		 * TODO document this function
		*/
		~Win32Data() {
			DeleteObject(backgroundBrush);
		}
	
		/**
		 * TODO document this function
		*/
		HWND getHandle() const { return handle; }

		/**
		 * TODO document this function
		*/
		ControlID getID() const { return id; }

		/**
		 * TODO document this function
		*/
		LRESULT callDefaultWindowProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp) const{
			return CallWindowProc(defaultWindowProc, handle, msg, wp, lp);
		}

		/**
		 * TODO document this function
		*/
		void setBackgroundColor(const Color c) {
			backgroundColor = c;
			DeleteObject(backgroundBrush);
			backgroundBrush = CreateSolidBrush(RGB(backgroundColor.r, backgroundColor.g, backgroundColor.b));
		}

		/**
		 * TODO document this function
		*/
		void setTextColor(const Color c) {
			textColor = c;
		}

		/**
		 * TODO document this function
		*/
		HBRUSH getBackgroundBrush() const {
			return backgroundBrush;
		}

		/**
		 * TODO document this function
		*/
		Color getBackgroundColor() const {
			return backgroundColor;
		}

		/**
		 * TODO document this function
		*/
		Color getTextColor() const { return textColor; }
};
}

#endif