#include "Window.hpp"

Window::Window()
{
	//Set default size, position, and title
	setX(0);
	setY(0);
	setWidth(250);
	setHeight(250);	
	setText("Default Window");
	resizable = true;	
}

Window::~Window()
{
	DeleteDC(hdcBuf);
}

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			//Initialize Menu
			HMENU menu = CreateMenu();

			MENUINFO mi;
			memset(&mi, 0, sizeof(mi));
			mi.cbSize = sizeof(mi);
			mi.fMask = MIM_STYLE;
			mi.dwStyle = MNS_NOTIFYBYPOS;
			SetMenuInfo(menu, &mi);

			for (int i = 0; i < menues.size(); i++)
			{
				AppendMenu(menu, MF_POPUP, (UINT_PTR) menues[i].getHandle(), 
							menues[i].getText().c_str());
			}
			
			SetMenu(hwnd, menu);
			
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			
			RECT r;
			GetClientRect(hwnd, &r);
			setWidth(r.right);
			setHeight(r.bottom);
			
			BitBlt(
				hdc,
				0, 0,
				getWidth(), getHeight(),
				hdcBuf,
				0, 0,
				SRCCOPY);
			EndPaint(hwnd, &ps);
			break;
		}
		case WM_COMMAND:
		{
			break;
		}
		case WM_MENUCOMMAND:
		{
			break;
		}
		case WM_SIZE:
		{
			setWidth(LOWORD(lp));
			setHeight(HIWORD(lp));
			HDC hdc = GetDC(hwnd);
			Gdiplus::Graphics g(hdc);
			g.Clear(Gdiplus::Color::White);
			BitBlt(
				hdc,
				0, 0,
				getWidth(), getHeight(),
				hdcBuf,
				0, 0,
				SRCCOPY);
			ReleaseDC(hwnd, hdc);
			
			break;
		}
		case WM_EXITSIZEMOVE:
		{
			resetBuffer();
			break;
		}
		case WM_LBUTTONDOWN:
		{
			events.push(Event(MOUSE_LEFT_DOWN, 0, 0));
			break;
		}
		case WM_RBUTTONDOWN:
		{
			events.push(Event(MOUSE_RIGHT_DOWN, 0, 0));
			break;
		}
		case WM_KEYDOWN:
		{
			switch (wp)
			{
				case VK_UP:
				{
					events.push(Event(ARROW_UP_PRESS, 0, 0));
					break;
				}
				case VK_DOWN:
				{
					events.push(Event(ARROW_DOWN_PRESS, 0, 0));
					break;
				}
				case VK_LEFT:
				{
					events.push(Event(ARROW_LEFT_PRESS, 0, 0));
					break;
				}
				case VK_RIGHT:
				{
					events.push(Event(ARROW_RIGHT_PRESS, 0, 0));
					break;
				}
				case 'C':
				{
					events.push(Event(C_KEY_PRESS, 0, 0));
					break;
				}
			}
			break;
		}
		case WM_KEYUP:
		{
			switch (wp)
			{
				case VK_UP:
				{
					events.push(Event(ARROW_UP_RELEASE, 0, 0));
					break;
				}
				case VK_DOWN:
				{
					events.push(Event(ARROW_DOWN_RELEASE, 0, 0));
					break;
				}
				case VK_LEFT:
				{
					events.push(Event(ARROW_LEFT_RELEASE, 0, 0));
					break;
				}
				case VK_RIGHT:
				{
					events.push(Event(ARROW_RIGHT_RELEASE, 0, 0));
					break;
				}
			}
			break;
		}
		case WM_ERASEBKGND:
			return (LRESULT) 1;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
			break;
		}
		default:	return DefWindowProc(hwnd, msg, wp, lp);
	}
}

void Window::resetBuffer()
{
	//Delete current buffer
	DeleteDC(hdcBuf);
	
	//Reset Buffers
	HDC hdc = GetDC((HWND) getHandle());

	hdcBuf = CreateCompatibleDC(hdc);
	HBITMAP b = CreateCompatibleBitmap(hdc, getWidth(), getHeight());

	HBITMAP oldbmp = (HBITMAP)SelectObject(hdcBuf, b);
	DeleteObject(oldbmp);

	ReleaseDC((HWND) getHandle(), hdc);
	
	fillBg();
}

int Window::show()
{
	//Create Window and set handle
	setHandle(CreateWindowEx(
				0,
				"BWindow",
				getText().c_str(),
				WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | resizable*WS_THICKFRAME,
				
				getX(), getY(), getWidth(), getHeight(),
				
				NULL,
				NULL,
				NULL,
				this));	
				
	//Show window
	ShowWindow((HWND) getHandle(), SW_SHOW);
	UpdateWindow((HWND) getHandle());
	SetFocus((HWND) getHandle());
	
	//Initialize buffer
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
	
	//Invalidate client area
	InvalidateRect((HWND) getHandle(), NULL, FALSE);
	
	//Clear buffer
	fillBg();
	
	return 1;
}

void Window::close()
{
	//Post the close message
	PostMessage((HWND) getHandle(), WM_CLOSE, 0, 0);
	
	//Handle remaining messages
	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

void Window::drawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(hdcBuf, x1, y1, NULL);
	LineTo(hdcBuf, x2, y2);
}

void Window::drawRect(int x, int y, int width, int height)
{
	Gdiplus::Graphics g(hdcBuf);
	Gdiplus::Pen p(Gdiplus::Color(255, 0, 0, 0));
	g.DrawRectangle(&p, x, y, width, height);
}

void Window::drawText(std::string text, int x, int y)
{
	Gdiplus::Graphics g(hdcBuf);
	Gdiplus::FontFamily fontFamily(L"Times New Roman");
	Gdiplus::Font font(&fontFamily, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	Gdiplus::PointF pointF(x, y);
	Gdiplus::SolidBrush solidBrush(Gdiplus::Color(255, 0, 0, 0));

	std::wstring t = std::wstring(text.begin(), text.end());
	g.DrawString(t.c_str(), -1, &font, pointF, &solidBrush);
}

void Window::fillBg()
{
	Gdiplus::Graphics g(hdcBuf);
	g.Clear(Gdiplus::Color::White);
}

void Window::addMenu(Menu m)
{
	menues.push_back(m);
}

void Window::setResizable(bool r) { resizable = r; }

bool Window::isResizable() { return resizable; }

Event Window::getNextEvent()
{
	Event e = events.front();
	events.pop();
	return e;
}

void Window::addEvent(Event e) { events.push(e); }

bool Window::hasEvents() { return !events.empty(); }
