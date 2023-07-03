#include "ControlHandling/Win32/FontHandler.hpp"

#include <wingdi.h>
#include <iostream>

using namespace BrazzGUI;
using namespace BrazzGUI::ControlHandling;

std::map<Font, HFONT, std::function<bool(const Font&, const Font&)>> FontHandler::fontMap{
	[](const Font& f1, const Font& f2)
	{
		return f1.getSize() < f2.getSize();
	}
};

HFONT FontHandler::getFontHandle(const Font& f)
{	
	if (fontMap.count(f)) return fontMap[f];
	
	fontMap[f] = CreateFont(
		f.getSize(),
		0.5*f.getSize(),
		0,	// Escapement angle
		0,	// Orientation angle
		FW_NORMAL,	// No bold
		false,	// Italic
		false,	// Underline
		false,	// Strikeout
		DEFAULT_CHARSET,	// Character Set
		OUT_DEFAULT_PRECIS,	// Output precision
		CLIP_DEFAULT_PRECIS,	// Clipping precision
		DEFAULT_QUALITY,	// Quality
		FF_DONTCARE | DEFAULT_PITCH,	// Pitch & family
		"Arial"	// Font name
	);
	if (fontMap[f] == NULL) std::cout << "NULL HFONT!!!\n";
	
	return fontMap[f];
}