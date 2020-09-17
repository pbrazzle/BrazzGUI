/*
*
*	Window class
*	Basic wrapper class for WIN32 windows
*
*/

#ifndef WINDOW
#define WINDOW

#include "Component.hpp"
#include "Menu.hpp"
#include "Event.hpp"

#include <vector>
#include <queue>
#include <windows.h>
#include <gdiplus.h>
#include <string>

class Window : public Component{
	private:
	
		//Vectors for Menues, Controls, and Event queue
		// (Assuming I add support for these eventually)
		std::vector<Menu> menues;
		//std::vector<Control> controls;
		std::queue<Event> events;
		
		//Extra styles
		bool resizable;
		
		//Buffers for drawing to the Window
		HDC hdcBuf;
		
		//WIN32 WndProc
		LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
		
		/*
		* resetBuffers()
		* Resizes and reallocates the draw buffers
		*/
		void resetBuffer();
		
		//This helps for initialization and MessageRouter function
		friend class BrazzCore;
		
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
		* Redraws the client area of the Window
		* returns a positive int if Window is still open, 0 if it has been closed, 
		* and a negative value if an error occured
		*/
		int update();
		
		/*
		* click(int, int)
		* Clicks the Windows at the given coordinates
		*/
		void click(int, int);
		
		/*
		* close()
		* Closes the Window
		*/
		void close();
		
		/*********** Drawing Functions (Move to Brush class???) ***********/
		
		/*
		* drawLine(int, int, int, int)
		* Draws a line onto the client area
		* Takes x1,y1,x2,y2 coordinates
		*/
		void drawLine(int, int, int, int);
		
		/*
		* drawPixel(int, int)
		* Draws a single pixel at given coordinates
		*/
		void drawPixel(int, int);
		
		/*
		* fillBg()
		* Fills Window background with given Color
		*/
		void fillBg();
		
		/*
		* fillRect(int, int, int, int)
		* Draws a filled rectangle to the Window buffer
		* First 2 ints are x and y pos, last 2 are width and height
		*/
		void fillRect(int, int, int, int);
		
		/*
		* drawRect(int, int, int, int)
		* Draws an empty rectangle to the Window buffer
		* First 2 ints are x and y pos, last 2 are width and height
		*/
		void drawRect(int, int, int, int);
		
		/*
		* drawText(string, int, int)
		* Draws text to the Window buffer
		* Takes a string and the xy pos of the text
		*/
		void drawText(std::string, int, int);
		
		/*********** Setters/Getters ***********/
		
		/*
		* addMenu()
		* Adds a Menu to the Window
		*/
		void addMenu(Menu);
		
		/*
		* setResizable(bool)
		* Sets Windows resizable parameter
		*/
		void setResizable(bool);
		
		/*
		* isResizable()
		* Returns bool for whether or not Window is resizable
		*/
		bool isResizable();
		
		/*
		* getNextEvent()
		* Retrieves next Event from the queue 
		*/
		Event getNextEvent();
		
		/*
		* addEvent(Event)
		* Queues up a new Event
		*/
		void addEvent(Event);
		
		/*
		* hasEvents()
		* Returns true if Window has waiting Events, false otherwise
		*/
		bool hasEvents();
};

#endif