#ifndef BRAZZGUIWINDOW
#define BRAZZGUIWINDOW

#include "GUIHandle.h"
#include "EventHandler.h"
#include "BasicControl.h"

#include <vector>
#include <functional>
#include <memory>

class Window : public BasicControl
{
	private:
		std::shared_ptr<GUIHandle> handle;
		std::shared_ptr<EventHandler> eventHandler;
		
	public:
		Window();
		
		//Style control
		void show();
		void setVisible(bool);
		
		void setWidth(int);
		void setHeight(int);
		void setX(int);
		void setY(int);
		
		//Parent/child getters/setters
		void setParent(const BasicControl&);
		BasicControl* getParent();
		
		void addChild(const BasicControl&);
		std::vector<BasicControl*> getChildren();
		
		//Event callback setters
		void setClickCallback(std::function<void()>);
};

#endif