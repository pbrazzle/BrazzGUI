#ifndef TEXT_CONTROL
#define TEXT_CONTROL

#include "Control.hpp"

namespace BrazzGUI
{
	class TextControl : public Control
	{
		public:
			TextControl(const ControlCreation::ControlType& type);
			virtual ~TextControl() = 0;
	};
}

#endif