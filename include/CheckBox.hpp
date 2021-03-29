#ifndef CHECKBOX
#define CHECKBOX

#include "Control.hpp"

class CheckBox : public Control
{
	private:
		bool checked = false;
		
	public:
		CheckBox();
		CheckBox(int,int,int,int);
		
		void click();
		
		bool isChecked();
};

#endif