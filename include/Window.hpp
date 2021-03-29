/*
*	Window class
*	Basic wrapper class for WIN32 windows
*/

#ifndef WINDOW
#define WINDOW

#include "DrawableGUIEntity.hpp"
#include "Control.hpp"
#include "Menu.hpp"

#include <string>
#include <vector>
#include <windows.h>

class Window : public DrawableGUIEntity{
	private:
		static BOOL CALLBACK updateProc(HWND, LPARAM);
	
		//Static data for GDI+
		static bool GDIPlusInitialized;
		static ULONG_PTR GDIPlusToken;
		static unsigned int count;
		
		//Extra styles
		bool resizable, changed;
		
		//void updateSize();
		void initialize();
		
		Menu* menu = nullptr;
		
	public:
	
		//Constructor
		Window();
		
		//Destructor
		~Window();
		
		/*********** Basic Functionality ***********/

		/*
		* show()
		* Shows the Window
		* returns 0 if successful, -1 otherwise
		*/
		int show();
		
		/*
		* update()
		* Handles the current waiting messages for the Window
		* returns a positive int if Window is still open, 0 if it has been closed, 
		* and a negative value if an error occured
		*/
		int update();
		
		/*
		* close()
		* Closes the Window
		*/
		void close();
		
		void click();
		void changeSize();
		void exitResize();
		void destroy();
		
		/*********** Setters/Getters ***********/
		
		void setResizable(bool);
		void setMenu(Menu&);
		void addChild(GUIEntity&);
		bool isResizable();
};

#endif