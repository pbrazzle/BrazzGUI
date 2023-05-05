#ifndef CONTROL_STYLING
#define CONTROL_STYLING

#include "ControlID.hpp"

#include <string>

namespace BrazzGUI
{
	namespace ControlStyling
	{
		void show(const ControlID&);
		
		void setX(const ControlID&, const int&);
		void setY(const ControlID&, const int&);
		void setWidth(const ControlID&, const int&);
		void setHeight(const ControlID&, const int&);
		
		void setText(const ControlID&, const std::string&);
		
		int getX(const ControlID&);
		int getY(const ControlID&);
		int getWidth(const ControlID&);
		int getHeight(const ControlID&);
		
		std::string getText(const ControlID&);
	}
}

#endif