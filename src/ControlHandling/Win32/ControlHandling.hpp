#ifndef WIN32_CONTROL_HANDLING
#define WIN32_CONTROL_HANDLING

#include "ControlHandling/ControlHandling.hpp"
#include <windows.h>

namespace BrazzGUI::ControlHandling
{
	class Win32Data : public ControlOSData
	{
		private:
			HWND handle;
			WNDPROC defaultWindowProc;
			ControlID id;

		public:
			Win32Data(const ControlID i, const HWND h, const WNDPROC defProc = &DefWindowProc) 
			: id(i), handle(h), defaultWindowProc(defProc) { }
		
			HWND getHandle() const { return handle; }

			ControlID getID() const { return id; }

			LRESULT callDefaultWindowProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp) const{
				return CallWindowProc(defaultWindowProc, handle, msg, wp, lp);
			}
	};
}

#endif