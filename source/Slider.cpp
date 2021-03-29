#include "Slider.hpp"

#include <windows.h>

Slider::Slider(int x, int y, int w, int h) : Control(x,y,w,h)
{
	
}

Slider::Slider() : Slider(0,0,100,100) { }