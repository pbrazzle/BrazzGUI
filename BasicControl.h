#ifndef BASE_CONTROL
#define BASE_CONTROL

//Interface for basic BrazzGUI controls

#include <vector>
#include <functional>

class BasicControl
{
	public:
		//Style control
		virtual void show() = 0;
		virtual void setVisible(bool) = 0;
		
		virtual void setWidth(int) = 0;
		virtual void setHeight(int) = 0;
		virtual void setX(int) = 0;
		virtual void setY(int) = 0;
		
		//Parent/child getters/setters
		virtual void setParent(const BasicControl&) = 0;
		virtual BasicControl* getParent() = 0;
		
		virtual void addChild(const BasicControl&) = 0;
		virtual std::vector<BasicControl*> getChildren() = 0;
		
		//Event callback setters
		virtual void setClickCallback(std::function<void()>) = 0;
};

#endif