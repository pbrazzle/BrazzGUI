#ifndef GUIENTITY
#define GUIENTITY

#include "OSInterface.hpp"

#include <windows.h>
#include <string>

//Message Defines
//We'll see about this...
#define LEFTMOUSE_DOWN 0

class GUIEntity
{
	private:
		void resize();
	
		std::string text = "Default", className = "BWindow";
		DWORD style;
		WNDPROC defProc = DefWindowProc;
		HWND handle = NULL, parent = NULL;
		int x = 0, y = 0, width = 100, height = 100, borderWidth = 0, borderHeight = 0;
		position pos;
		bool created = false;
		COLORREF bgColor = RGB(255,255,0), textColor = RGB(255,0,0);
		
		virtual void initialize();
		virtual void paint();
		virtual void changeSize();
		virtual void exitResize();
		virtual void destroy();
		virtual void command();
		
		friend class Window;
		friend class ControlGroup;
		friend void* OSInterface::handleMessage(GUIEntity*, unsigned int, void*, void*);
		
		//Remove this once win32 stuff is interfaced
		friend void OSInterface::create(GUIEntity*);
		friend LRESULT OSInterface::MessageRouter(HWND, UINT, WPARAM, LPARAM);
	
	protected:
		virtual void create();
		void updateSize();
		
		void setBorderWidth(unsigned int);
		void setBorderHeight(unsigned int);
		void setClassName(std::string);
		void setStyle(DWORD);
		void setParent(HWND);
		
		HWND getHandle();
		
		//Perhaps this will include some sort of Event class????
		//virtual void action(unsigned int);
		
		
	public:	
		GUIEntity();
		GUIEntity(int,int,int,int);
	
		virtual ~GUIEntity() { };
		
		virtual void click();
		virtual int update();
		
		virtual void setX(int);
		virtual void setY(int);
		virtual void setWidth(unsigned int);
		virtual void setHeight(unsigned int);
		void setText(std::string);
		void setBgColor(int,int,int);
		void setVScroll(bool);
		
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		std::string getText();
};



#endif