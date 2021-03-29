#ifndef BUTTON
#define BUTTON

#include "Control.hpp"

#include <string>

class Button : public Control
{
	private:
		void (*clickAction)();
	
	public:
		Button();
		Button(int,int,int,int);
		
		void action(void*);
		void click();
		void setClickAction(void (*)());
};

#endif