#ifndef BRAZZGUI_TAB_GROUP
#define BRAZZGUI_TAB_GROUP

#include "Control.hpp"

#include <vector>

namespace BrazzGUI {
/*
 *   The TabGroup handles multiple groups of Controls selected by tabs
 */
class TabGroup : public Control {
    private:
    std::vector<Control*> tabControls;

    public:
    /*
     *   Creates a TabGroup
     */
    TabGroup();

    /*
     *   Adds a new tab
     *
     *  @param tabName Display text for the tab
     * @param tabControl Top-level Control for the tab
     */
    void addTab(std::string tabName, Control* tabControl);

    int getClientWidth() const;
    int getClientHeight() const;
};
} // namespace BrazzGUI

#endif