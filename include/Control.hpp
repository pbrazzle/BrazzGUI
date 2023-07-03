#ifndef CONTROL
#define CONTROL

#include "ControlID.hpp"
#include "Font.hpp"
#include "Color.hpp"

namespace BrazzGUI::ControlCreation
{
enum class ControlType;
}

#include <string>

namespace BrazzGUI
{
	class Control
	{
		private:
			Font font;
			Color backgroundColor;
			Color textColor;
			
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
			void setBackgroundColor(const Color);
			void setTextColor(const Color);
			
			void setText(const std::string&);
			
			void setFontSize(const int&);
			
			int getX() const;
			int getY() const;
			int getWidth() const;
			virtual int getHeight() const;
			int getFontSize() const;
			Color getBackgroundColor() const;
			Color getTextColor() const;
			
			std::string getText() const;
			
			ControlID getID() const;
	};
}

#endif