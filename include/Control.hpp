#ifndef CONTROL
#define CONTROL

#include "ControlID.hpp"
#include "ControlHandling/ControlCreation.hpp"
#include "Font.hpp"

#include <string>

namespace BrazzGUI
{
	class Control
	{
		private:
			Font font;
			
		protected:
			ControlID id;
			
		public:
			Control(const ControlCreation::ControlType& type);
			virtual ~Control() = 0;
			
			void show();
			
			void setX(const int&);
			void setY(const int&);
			void setWidth(const int&);
			void setHeight(const int&);
			void setPosition(const int&, const int&, const int&, const int&);
			
			void setText(const std::string&);
			
			void setFontSize(const int&);
			
			int getX() const;
			int getY() const;
			int getWidth() const;
			virtual int getHeight() const;
			int getFontSize() const;
			
			std::string getText() const;
			
			ControlID getID() const;
	};
}

#endif