#include "BrazzCore.hpp"

#include <string>
#include <windows.h>

int main()
{
	Window myWindow;
	myWindow.setText("BrazzText");
	myWindow.setWidth(200);
	myWindow.setHeight(200);
	
	ComboBox cb(0,0,100,20);
	//myWindow.addChild(cb);
	
	ListViewer lv(0,100,100,100);
	myWindow.addChild(lv);

	myWindow.show();
	
	while (myWindow.update()) { }
	
	return 0;
}
