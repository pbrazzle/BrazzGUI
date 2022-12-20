#include "BrazzGUIApp.h"

#include <windows.h>

BrazzGUIApp::BrazzGUIApp() { }

void BrazzGUIApp::run()
{
	MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}