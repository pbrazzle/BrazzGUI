#ifndef CONTROL_HANDLING
#define CONTROL_HANDLING

#include "ControlID.hpp"

#include <map>
#include <memory>

namespace BrazzGUI
{
	namespace ControlHandling
	{
		class ControlOSData
		{
			public:
				virtual ~ControlOSData() = 0 { }
		};

		const ControlOSData& getDataFromID(const ControlID&);
	}
}

#endif