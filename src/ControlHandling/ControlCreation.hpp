#ifndef CONTROL_CREATION
#define CONTROL_CREATION

#include "ControlID.hpp"

namespace BrazzGUI
{
	namespace ControlCreation
	{
		enum class ControlType
		{
			Window
		};
		
		ControlID createControl(const ControlType& type);
	}
}

#endif