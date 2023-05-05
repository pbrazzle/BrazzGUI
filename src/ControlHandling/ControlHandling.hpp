#ifndef CONTROL_HANDLING
#define CONTROL_HANDLING

#include "ControlID.hpp"

#include <map>
#include <memory>
#include <vector>

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
		
		const std::vector<std::unique_ptr<ControlOSData>>& getTopWindows();
	}
}

#endif