#ifndef TEXTBOX
#define TEXTBOX

#include "Control.hpp"

#include <string>

class TextBox : public Control
{
	public:
		TextBox();
		TextBox(int, int, int, int);
		
		bool getTextAsInt(int*);
		bool getTextAsDouble(double*);
		
		void setFontSize(int);
};

#endif