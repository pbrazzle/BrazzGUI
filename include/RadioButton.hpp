#ifndef RADIOBUTTON
#define RADIOBUTTON

#include "Control.hpp"

class RadioButton : public Control
{
	private:
		friend class RadioGroup;
	
		bool clicked = false, checked = false;
		
	public:
		RadioButton();
		RadioButton(int,int,int,int);
		
		void click();
};

#endif