#ifndef BRAZZCORE
#define BRAZZCORE

//Lib Includes
#include "BrazzCore.hpp"
#include "Component.hpp"
#include "Window.hpp"
#include "Menu.hpp"
#include "Event.hpp"

//Other includes
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

extern int BrazzApp();

//Class for app initialization
class BrazzCore{
	private:
		static LRESULT CALLBACK MessageRouter(HWND, UINT, WPARAM, LPARAM);
		
	public:
		static bool registerWindows();
};

#endif