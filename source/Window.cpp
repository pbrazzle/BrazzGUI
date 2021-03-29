#include "Window.hpp"
#include "Brush.hpp"

#include <windows.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

#include <string>

bool Window::GDIPlusInitialized = false;
ULONG_PTR Window::GDIPlusToken;
unsigned int Window::count = 0;

BOOL CALLBACK Window::updateProc(HWND h, LPARAM l)
{
	GUIEntity* entity;
	entity = (GUIEntity*)GetWindowLongPtr(h, GWLP_USERDATA);
	return (BOOL) entity->update();
}

Window::Window()
{
	//Set defaults
	resizable = true;
	
	//Initialize GDI+ if needed
	if(!GDIPlusInitialized)
	{	
		Gdiplus::GdiplusStartupInput input;
		if (Gdiplus::GdiplusStartup(&GDIPlusToken, &input, NULL) != Gdiplus::Ok)
		{
			MessageBox(NULL, "GDI+ initialization failed!", "!!!", MB_OK);
		}
		GDIPlusInitialized = true;
	}	
	
	setClassName("BWindow");
	setStyle(WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_BORDER);
	setParent(NULL);
				
	count++;
}

Window::~Window()
{
	//Shutdown GDI+ if this is the only window
	if (count == 1)
	{
		Gdiplus::GdiplusShutdown(GDIPlusToken);
		GDIPlusInitialized = false;
	}
	count--;
}

void Window::changeSize()
{
	//updateSize();
	resetBuffer();
}

void Window::exitResize()
{
	//resetBuffer();
}

void Window::destroy()
{
	PostQuitMessage(0);
}

int Window::show()
{
	//Show window
	ShowWindow(getHandle(), SW_SHOW);
	UpdateWindow(getHandle());
	SetFocus(getHandle());

	//Initialize buffer;
	updateSize();
	resetBuffer();

	return 0;
}

int Window::update()
{	
	//Handle message queue
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) return 0;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	//Update layout controls
	EnumChildWindows(getHandle(), &updateProc, (LPARAM) 0);
	
	//Check for menu update
	if (menu != nullptr)
	{
		if (menu->updated)
		{	
			menu->updated = false;
			int currHeight = getHeight();
			DrawMenuBar(getHandle());
			setHeight(currHeight);
		}
	}
	
	return 1;
}

void Window::close()
{
	//Post the close message
	PostMessage(getHandle(), WM_CLOSE, 0, 0);
	
	//Handle remaining messages
	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

void Window::addChild(GUIEntity &c)
{ 
	c.setParent(getHandle()); 
}

void Window::setMenu(Menu& m)
{
	menu = &m;
	int currHeight = getHeight();
	SetMenu(getHandle(), menu->handle);
	setHeight(currHeight);
}

void Window::setResizable(bool r) { resizable = r; }

bool Window::isResizable() { return resizable; }

void Window::click() { }

void Window::initialize() { }