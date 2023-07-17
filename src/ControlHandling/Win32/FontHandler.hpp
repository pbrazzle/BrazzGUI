#ifndef WIN32_FONTHANDLER
#define WIN32_FONTHANDLER

#include "Font.hpp"

#include <functional>
#include <map>
#include <windows.h>

namespace BrazzGUI::ControlHandling {
/**
 * The FontHandler converts a BrazzGUI font to a Win32 font
 */
class FontHandler {
    private:
    /**
     * Maps BrazzGUI fonts to Win32 HFONTs
     */
    static std::map<Font, HFONT, std::function<bool(const Font&, const Font&)>>
        fontMap;

    public:
    /**
     * Gets the Win32 HFONT for a given BrazzGUI Font
     * If the font is not already registered with Win32, creates a new HFONT
     *
     * @param font A BrazzGUI Font
     * @return HFONT for the given BrazzGUI Font
     */
    static HFONT getFontHandle(const Font& font);
};
} // namespace BrazzGUI::ControlHandling

#endif