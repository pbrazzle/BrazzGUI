#ifndef BRUSH
#define BRUSH

#include "Window.hpp"

#include <string>

class Brush
{
	private:
		HWND handle;
		HDC bitmap;
		
	public:
		Brush(DrawableGUIEntity&);
		void fillBackground();
		void drawLine(int,int,int,int);
		void drawRect(int,int,int,int);
		void drawText(std::string,int,int);
};

#endif