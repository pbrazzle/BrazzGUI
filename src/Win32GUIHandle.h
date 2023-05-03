#ifndef WIN32GUIHANDLE
#define WIN32GUIHANDLE

#include "GUIHandle.h"

class Win32GUIHandle : public GUIHandle
{
	private:
		HWND handle;
		
	public:
		Win32GUIHandle();
	
		//Style control
		void setVisible(bool);
		
		void setWidth(int);
		void setHeight(int);
		void setX(int);
		void setY(int);
		
		//Handle getter
		HWND getHandle() const;
		
		//Set parent
		void setParent(const GUIHandle&);
};

#endif