#ifndef OSINTERFACE
#define OSINTERFACE

//Message Defines
/***Special Messages***/
#define NO_HANDLE 0xF0

/***Get Messages***/
#define OS_GETTEXT 0x0
#define OS_GETPOS 0x1

/***Set Messages***/
#define OS_SETTEXT 0x100
#define OS_SETPOS 0x101
#define OS_SETSIZE 0x102

/***User Messages***/
#define LCLICK 0x10
#define COMMAND 0x11

/***Graphical Messages***/
#define PAINT 0x20
#define REPAINT 0x21
#define RESIZE 0x22
#define RESIZE_EXIT 0x23
#define SET_COLORS 0x24

/***Memory Messages***/
#define DESTROY 0x30

#include <windows.h>
class GUIEntity;

//Structs
struct position
{
	int x = 0, y = 0, width = 0, height = 0;
};

struct Win32Data
{
	GUIEntity* entity;
	HWND handle;
	WNDPROC defProc;
	DWORD style;
};

namespace OSInterface
{
	//OS specific
	LRESULT CALLBACK MessageRouter(HWND, UINT, WPARAM, LPARAM);
	
	//Uses BrazzGUI Messages
	void* handleMessage(GUIEntity*, unsigned int, void*, void*);
	
	void create(GUIEntity*);
}

#endif