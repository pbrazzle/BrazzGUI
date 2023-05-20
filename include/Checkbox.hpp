#ifndef CHECKBOX
#define CHECKBOX

#include "Control.hpp"

namespace BrazzGUI
{
	class Checkbox : public Control
	{
		public:
			Checkbox();
			
			bool isChecked();
			void setCheck(const bool&);
	};
}

#endif