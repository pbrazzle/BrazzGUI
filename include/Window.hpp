#ifndef WINDOW
#define WINDOW

#include "ControlID.hpp"

namespace BrazzGUI
{
	class Window
	{
		private:
			ControlID id;
			
		public:
			Window();
			
			void show();
	};
}

#endif