#pragma once

#include <memory>

namespace BrazzGUI {
class Window;
class MenuItem;
} // namespace BrazzGUI

namespace BrazzGUI::Handlers {
/*
 *   TODO document this class
 */
class MenuHandler {
    public:
    /*
     *   TODO document this function
     */
    virtual ~MenuHandler() {}

    /*
     * TODO document this function
     */
    virtual void addTopLevelItem(const Window& window,
                                 const MenuItem& item) = 0;

    /*
     *   TODO document this function
     */
    virtual void addSubItem(const MenuItem& parent, const MenuItem& child) = 0;
};

/*
 *   TODO document this function
 */
std::unique_ptr<MenuHandler> getDefaultMenuHandler();
} // namespace BrazzGUI::Handlers