#include "ListViewer.hpp"

#include <windows.h>
#include <string>

ListViewer::ListViewer(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("LISTBOX");
	setStyle(WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL | WS_BORDER);
}

ListViewer::ListViewer() : ListViewer(0,0,100,100) { }

void ListViewer::initialize()
{
	if (items.size() > 0)
	{
		for (std::string s : items) SendMessage(getHandle(), LB_ADDSTRING, 0, (LPARAM) s.c_str());
	}
}

void ListViewer::addItem(std::string s)
{
	items.push_back(s);
	SendMessage(getHandle(), LB_ADDSTRING, 0, (LPARAM) s.c_str());
}

std::string ListViewer::getSelectedItem()
{
	int index = SendMessage(getHandle(), LB_GETCURSEL, 0, 0);
	if (index == LB_ERR) return "";
	return items[index];
}

int ListViewer::getSelectedIndex()
{
	int index = SendMessage(getHandle(), LB_GETCURSEL, 0, 0);
	if (index == LB_ERR) return -1;
	return index;
}

void ListViewer::removeSelectedItem()
{
	int index = SendMessage(getHandle(), LB_GETCURSEL, 0, 0);
	if (index == LB_ERR) return;
	items.erase(items.begin()+index);
	SendMessage(getHandle(), LB_DELETESTRING, (WPARAM) index, 0);
}

void ListViewer::removeItem(int i)
{
	int check = SendMessage(getHandle(), LB_DELETESTRING, (WPARAM) i, 0);
	if (check == LB_ERR) return;
	items.erase(items.begin()+i);
}