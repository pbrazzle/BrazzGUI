#ifndef CONTROL_HANDLING
#define CONTROL_HANDLING

#include "Color.hpp"
#include "ControlID.hpp"

#include <map>
#include <memory>
#include <vector>

namespace BrazzGUI::ControlHandling {
/**
 * OS specific data for each Control
 */
class ControlOSData {
    public:
    virtual ~ControlOSData() = 0 {}

    virtual void setBackgroundColor(const Color) = 0;
    virtual void setTextColor(const Color) = 0;
};

/**
 * Finds the OSData for a given Control
 *
 * @param id ControlID for the Control
 * @return OSData for the Control
 */
ControlOSData& getDataFromID(const ControlID& id);

/**
 * Finds all top-level windows OSData in the application
 * New child Controls will be given to the first top-level window by default
 *
 * @return Vector of OSData for every top-level window
 */
const std::vector<std::unique_ptr<ControlOSData>>& getTopWindows();
} // namespace BrazzGUI::ControlHandling

#endif