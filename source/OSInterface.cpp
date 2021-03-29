#include "OSInterface.hpp"
#include "GUIEntity.hpp"

UINT last = 0;

/*
std::string GetLastErrorAsString()
{
    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if(errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }
    
    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
    
    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);
    
    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);
            
    return message;
}
*/

void OSInterface::create(GUIEntity* entity)
{	
	//Register window class if needed
	WNDCLASSEX w;
	if(!GetClassInfoEx(GetModuleHandle(NULL), "BWindow", &w))
	{
		WNDCLASS wc = { };
		
		wc.lpfnWndProc = DefWindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = "BWindow";
		wc.lpszMenuName = NULL;
		wc.hbrBackground = NULL;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		
		if(!RegisterClass(&wc))
		{		
			MessageBox(NULL, "Failed to register BWindow!", "", MB_OK);
			return;
		}
	}
	
	//Create Entity handle
	entity->handle = CreateWindowEx(0,
			entity->className.c_str(), entity->getText().c_str(),
			entity->style,
			entity->getX(), entity->getY(), entity->getWidth(), entity->getHeight(),
			entity->parent,
			NULL,
			(entity->parent != NULL) ? (HINSTANCE)GetWindowLongPtr(entity->parent, GWLP_HINSTANCE) : NULL,
			entity);
			
	if (entity->handle == NULL)
	{
		MessageBox(NULL, "Failed to create entity!", "", MB_OK);
		return;
	}
		
	SetWindowLongPtr(entity->handle, GWLP_USERDATA, (LONG_PTR) entity);
	entity->defProc = (WNDPROC) SetWindowLongPtr(entity->handle, GWLP_WNDPROC, (LONG_PTR) MessageRouter);
}

//Routes Win32 Messages to BrazzGUI defined Messages
LRESULT CALLBACK OSInterface::MessageRouter(HWND h, UINT msg, WPARAM wp, LPARAM lp)
{
	last = msg;
	GUIEntity* entity;
	if (msg == WM_CREATE)
	{
		entity = (GUIEntity*) ((LPCREATESTRUCT) lp)->lpCreateParams;
		SetWindowLongPtr(h, GWLP_USERDATA, (LONG_PTR) entity);
		return 0;
	} else
	{
		entity = (GUIEntity*)GetWindowLongPtr(h, GWLP_USERDATA);
	}
	
	unsigned int brazzMsg = NO_HANDLE;
	switch(msg)
	{
		case WM_PAINT:
		{
			brazzMsg = PAINT;
			break;
		}
		case WM_DESTROY:
		{
			brazzMsg = DESTROY;
			break;
		}
		case WM_SIZE:
		{
			brazzMsg = RESIZE;
			break;
		}
		case WM_LBUTTONDOWN:
		{
			brazzMsg = LCLICK;
			break;
		}
		case WM_EXITSIZEMOVE:
		{
			brazzMsg = RESIZE_EXIT;
			break;
		}
		case WM_COMMAND:
		{
			brazzMsg = COMMAND;
			break;
		}
		case WM_CTLCOLORSTATIC:
		{
			brazzMsg = SET_COLORS;
			break;
		}
		case WM_CTLCOLOREDIT:
		{
			brazzMsg = SET_COLORS;
			break;
		}
		case WM_VSCROLL:
		{
			SCROLLINFO si;
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS;
			GetScrollInfo(h, SB_VERT, &si);
			
			int oldPos = si.nPos;
			
			switch(LOWORD(wp))
			{
				case SB_TOP: si.nPos = si.nMin; break;
				case SB_BOTTOM: si.nPos = si.nMax; break;
				case SB_LINEUP: si.nPos = si.nPos - 10; break;
				case SB_LINEDOWN: si.nPos = si.nPos + 10; break;
				case SB_PAGEUP: break;
				case SB_PAGEDOWN: break;
				case SB_THUMBTRACK: si.nPos = HIWORD(wp); break;
				case SB_THUMBPOSITION: si.nPos = HIWORD(wp); break;
			}
			
			SetScrollInfo(h, SB_VERT, &si, TRUE);
			ScrollWindowEx(h, 0, oldPos - si.nPos, NULL, NULL, NULL, NULL, SW_ERASE | SW_INVALIDATE);
			break;
		}
	}
	
	//Use defProc if BrazzGUI doesn't support this message
	if (brazzMsg == NO_HANDLE) return CallWindowProc(entity->defProc, h, msg, wp, lp);
	
	LRESULT result = (LRESULT) handleMessage(entity, brazzMsg, &wp, &lp);
	if (!result) return CallWindowProc(entity->defProc, h, msg, wp, lp);
	else return result;
}

void* OSInterface::handleMessage(GUIEntity* entity, unsigned int id, void* param, void* param2)
{
	switch (id)
	{
		case OS_GETTEXT:
		{
			int length = GetWindowTextLength(entity->handle);
			char* buf = new char[length+1];
			GetWindowText(entity->handle, buf, length+1);
			std::string s(buf);
			delete [] buf;
			*((std::string*) param) = s;
			break;
		}
		case OS_GETPOS:
		{
			RECT r;
			GetWindowRect(entity->handle, &r);
			position* pos = (position*) param;
			pos->x = r.left;
			pos->y = r.top;
			GetClientRect(entity->handle, &r);
			pos->width = r.right;
			pos->height = r.bottom;
			break;
		}
		case OS_SETTEXT:
		{
			SetWindowText(entity->handle, ((std::string*) param)->c_str());
			break;
		}
		case OS_SETSIZE:
		{
			position pos = *((position*) param);
			RECT r;
			r.left = r.top = 0;
			r.right = pos.width;
			r.bottom = pos.height;
	
			int expHeight = pos.height, expWidth = pos.width;
	
			if (GetMenu(entity->handle) != NULL) AdjustWindowRect(&r, entity->style, GetMenuItemCount(GetMenu(entity->handle))>0);
			else AdjustWindowRect(&r, entity->style, false);
	
			SetWindowPos(entity->handle, NULL, 0, 0, r.right-r.left, r.bottom-r.top, SWP_NOMOVE | SWP_NOZORDER);
			break;
		}
		case OS_SETPOS:
		{
			position p = *((position*) param);
			SetWindowPos(entity->handle, NULL, p.x, p.y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
			break;
		}
		case LCLICK:
		{
			entity->click();
			break;
		}
		case PAINT:
		{
			entity->paint();
			break;
		}
		case REPAINT:
		{
			InvalidateRect(entity->handle, NULL, true);
			break;
		}
		case RESIZE:
		{
			entity->changeSize();
			break;
		}
		case RESIZE_EXIT:
		{
			entity->exitResize();
			break;
		}
		case DESTROY:
		{
			entity->destroy();
			break;
		}
		case COMMAND:
		{
			entity->command();
			break;
		}
		case SET_COLORS:
		{
			GUIEntity* child = (GUIEntity*)GetWindowLongPtr((HWND) *((HWND*) param2), GWLP_USERDATA);
			COLORREF bgColor = child->bgColor, textColor = child->textColor;
			SetBkColor((HDC) *((HDC*) param), bgColor);
			SetDCBrushColor((HDC) *((HDC*) param), bgColor);
			return (void*) GetStockObject(DC_BRUSH);
			break;
		}
	}
	return 0;
}