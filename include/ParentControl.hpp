#ifndef BRAZZGUI_PARENT_CONTROL
#define BRAZZGUI_PARENT_CONTROL

#include "Control.hpp"
#include "LayoutController.hpp"

namespace BrazzGUI {

/**
 * TODO document this class
 */
class ParentControl : public Control {
    private:
    LayoutController layout;

    public:
    /**
     * TODO document this function
     */
    ParentControl(const ControlCreation::ControlType);

    /**
     * TODO document this function
     */
    virtual ~ParentControl() = 0 {}

    /**
     * TODO document this function
     */
    void addControl(Control &);

    /**
     * TODO document this function
     */
    void addControl(Control &, const LayoutType);

    /**
     * TODO document this function
     */
    void updateLayout();

    /**
     * TODO document this function
     */
    int getClientWidth();

    /**
     * TODO document this function
     */
    int getClientHeight();
};

} // namespace BrazzGUI

#endif