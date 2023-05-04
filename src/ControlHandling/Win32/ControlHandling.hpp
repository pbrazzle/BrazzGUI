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
		public:
			Win32Data(const HWND& h) : handle(h) { }
		
			HWND getHandle() const { return handle; }
	};
}

#endif