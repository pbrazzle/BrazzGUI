#ifndef COMBOBOX
#define COMBOBOX

#include "Control.hpp"

namespace BrazzGUI
{
	class ComboBox : public Control
	{
		public:
			ComboBox();
			
			int getHeight() const override;
	};
}

#endif