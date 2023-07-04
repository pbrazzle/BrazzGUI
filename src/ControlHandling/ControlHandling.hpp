#ifndef CONTROL_HANDLING
#define CONTROL_HANDLING

#include "ControlID.hpp"
#include "Color.hpp"

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

				virtual void setBackgroundColor(const Color) = 0;
		};

		ControlOSData& getDataFromID(const ControlID&);
		
		const std::vector<std::unique_ptr<ControlOSData>>& getTopWindows();
	}
}

#endif