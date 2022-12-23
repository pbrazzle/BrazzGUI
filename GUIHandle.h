#ifndef GUIHANDLE
#define GUIHANDLE

#include <windows.h>

class GUIHandle
{
	public:
		//Style control
		virtual void setVisible(bool) = 0;
		
		virtual void setWidth(int) = 0;
		virtual void setHeight(int) = 0;
		virtual void setX(int) = 0;
		virtual void setY(int) = 0;
		
		//Handle getter
		virtual HWND getHandle() const = 0;
		
		//Set parent
		virtual void setParent(const GUIHandle&) = 0;
};

#endif