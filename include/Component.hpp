#ifndef COMPONENT
#define COMPONENT

#include <windows.h>
#include <string>

class Component{
	private:
		int x,y,width,height;
		HANDLE handle; 
		std::string className, text;
		DWORD style, extraStyles;
	public:
		//Getters
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		std::string getText() const;
		HANDLE getHandle() const;
		//Setters
		void setX(int);
		void setY(int);
		void setWidth(int);
		void setHeight(int);
		void setText(std::string);
		void setHandle(HANDLE);
};

#endif