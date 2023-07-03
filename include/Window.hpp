#ifndef WINDOW
#define WINDOW

#include "Control.hpp"
#include "LayoutController.hpp"

namespace BrazzGUI
{
	class Window : public Control
	{
		private:
			LayoutController layout;

		public:
			Window();
			
			void addControl(Control&);
			void addControl(Control&, const LayoutType);

			void updateLayout();

			int getClientWidth();
			int getClientHeight();
	};
}

#endif