#ifndef BRAZZGUI_TAB_GROUP
#define BRAZZGUI_TAB_GROUP

#include "Control.hpp"

#include <vector>

namespace BrazzGUI {
/*
 *   TODO document TabGroup
 */
class TabGroup : public Control {
    private:
    std::vector<Control*> tabControls;

    public:
    /*
     *   TODO document
     */
    TabGroup();

    /*
     *   TODO document
     */
    void addTab(std::string tabName, Control* tabControl);

    int getClientWidth() const;
    int getClientHeight() const;
};
} // namespace BrazzGUI

#endif