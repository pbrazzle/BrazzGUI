#include "BrazzCore.hpp"

LRESULT CALLBACK BrazzCore::MessageRouter(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Window* wnd;
	if (uMsg == WM_CREATE)
	{
		wnd = (Window*)(((LPCREATESTRUCT)lParam)->lpCreateParams);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)wnd);
	} else
	{
		wnd = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	}
	return wnd->WndProc(hwnd, uMsg, wParam, lParam);
}

bool BrazzCore::registerWindows()
{
	WNDCLASS wc = { };

	wc.lpfnWndProc = MessageRouter;
	wc.hInstance = NULL;
	wc.lpszClassName = "BWindow";
	wc.lpszMenuName = NULL;
	wc.hbrBackground = NULL;
	
	return RegisterClass(&wc);
}

//Application entry point
int main() 
{
	//Create default Window class
	if (!BrazzCore::registerWindows()){
		MessageBox(NULL, "Window class failed to register...", "...", MB_OK);
		return 0;
	}
	
	//Initialize GDI+
	Gdiplus::GdiplusStartupInput input;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &input, NULL);
	
	//Run user app
	BrazzApp();

	//Shutdown GDI+
	Gdiplus::GdiplusShutdown(token);
	
	return 0;
}