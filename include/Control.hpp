#ifndef CONTROL
#define CONTROL

#include "ControlID.hpp"
#include "ControlHandling/ControlCreation.hpp"

#include <string>

namespace BrazzGUI
{
	class Control
	{
		private:
			ControlID id;
			
		public:
			Control(const ControlCreation::ControlType& type);
			virtual ~Control() = 0;
			
			void show();
			
			void setX(const int&);
			void setY(const int&);
			void setWidth(const int&);
			void setHeight(const int&);
			
			void setText(const std::string&);
			
			int getX() const;
			int getY() const;
			int getWidth() const;
			int getHeight() const;
			
			std::string getText() const;
	};
}

#endif