#include "RadioGroup.hpp"
	
RadioGroup::RadioGroup() : RadioGroup(0,0,100,100) { }

RadioGroup::RadioGroup(int x,int y,int w,int h) : Control(x,y,w,h)
{
	setClassName("BWindow");
	setStyle(WS_CHILD | WS_VISIBLE);
}

void RadioGroup::initialize()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		//Configure button positions (vertically stacked evenly)
		buttons[i]->setX(0);
		buttons[i]->setY(i*(getHeight()/buttons.size()));
		buttons[i]->setWidth(getWidth());
		buttons[i]->setHeight(getHeight()/buttons.size());
		//Set button parent and create it
		buttons[i]->setParent(getHandle());
	}
}
		
void RadioGroup::addButton(RadioButton *rb)
{
	buttons.push_back(rb);
}

int RadioGroup::update()
{
	//Find which button was clicked
	int clickIndex = -1;
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i]->clicked) clickIndex = i;
	}	
	//End if no new clicks
	if (clickIndex < 0) return 1;
	
	//Handle clicked flag
	buttons[clickIndex]->clicked = false;
	if (buttons[clickIndex]->checked) return 1;
	else 
	{
		SendMessage(buttons[clickIndex]->getHandle(), BM_SETCHECK, BST_CHECKED, 0);
		buttons[clickIndex]->checked = true;
		if (checkedIndex >= 0)
		{
			SendMessage(buttons[checkedIndex]->getHandle(), BM_SETCHECK, BST_UNCHECKED, 0);
			buttons[checkedIndex]->checked = false;
		}
		checkedIndex = clickIndex;
	}
	
	return 1;
}

int RadioGroup::getSelectedIndex()
{
	return checkedIndex;
}

std::string RadioGroup::getSelectedName() { return buttons[checkedIndex]->getText(); }