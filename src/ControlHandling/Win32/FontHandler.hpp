#ifndef WIN32_FONTHANDLER
#define WIN32_FONTHANDLER

#include "Font.hpp"

#include <windows.h>
#include <map>
#include <functional>

namespace BrazzGUI::ControlHandling
{
	using namespace BrazzGUI;
	
	class FontHandler
	{
		private:
			static std::map<Font, HFONT, std::function<bool(const Font&, const Font&)>> fontMap;
		
		public:
			static HFONT getFontHandle(const Font&);
	};
}

#endif