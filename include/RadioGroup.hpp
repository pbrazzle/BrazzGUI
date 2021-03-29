#ifndef RADIOGROUP
#define RADIOGROUP

#include "RadioButton.hpp"

#include <vector>
#include <string>

class RadioGroup : public Control
{
	private:
		std::vector<RadioButton*> buttons;
		int checkedIndex = -1;
		
		void initialize();
	
	public:
		RadioGroup();
		RadioGroup(int,int,int,int);
		
		void addButton(RadioButton*);
		
		int update();
		
		int getSelectedIndex();
		std::string getSelectedName();
};

#endif