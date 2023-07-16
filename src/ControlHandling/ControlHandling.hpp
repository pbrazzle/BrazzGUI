#ifndef CONTROL_HANDLING
#define CONTROL_HANDLING

#include "Color.hpp"
#include "ControlID.hpp"

#include <map>
#include <memory>
#include <vector>

namespace BrazzGUI::ControlHandling {
/**
 * TODO document this class
 */
class ControlOSData {
    public:
    virtual ~ControlOSData() = 0 {}

    virtual void setBackgroundColor(const Color) = 0;
    virtual void setTextColor(const Color) = 0;
};

/**
 * TODO document this function
 */
ControlOSData &getDataFromID(const ControlID &);

/**
 * TODO document this function
 */
const std::vector<std::unique_ptr<ControlOSData>> &getTopWindows();
} // namespace BrazzGUI::ControlHandling

#endif