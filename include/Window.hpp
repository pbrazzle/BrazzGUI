#ifndef WINDOW
#define WINDOW

#include "Control.hpp"

namespace BrazzGUI
{
	class Window : public Control
	{
		public:
			Window();
			
			void addControl(const Control&);
	};
}

#endif