#ifndef WIN32_FONTHANDLER
#define WIN32_FONTHANDLER

#include "Font.hpp"

#include <windows.h>
#include <map>
#include <functional>

namespace BrazzGUI::ControlHandling
{
/**
 * TODO document this class
*/
class FontHandler
{
	private:
		/**
		 * TODO document this function
		*/
		static std::map<Font, HFONT, std::function<bool(const Font&, const Font&)>> fontMap;

	public:
		/**
		 * TODO document this function
		*/
		static HFONT getFontHandle(const Font&);
};
}

#endif