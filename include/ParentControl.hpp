#ifndef BRAZZGUI_PARENT_CONTROL
#define BRAZZGUI_PARENT_CONTROL

#include "Control.hpp"
#include "LayoutController.hpp"

namespace BrazzGUI
{

class ParentControl : public Control {
    private:
        LayoutController layout;

    public:
        ParentControl(const ControlCreation::ControlType);
        virtual ~ParentControl() = 0 { }

        void addControl(Control&);
        void addControl(Control&, const LayoutType);

        void updateLayout();

        int getClientWidth();
        int getClientHeight();
};

}

#endif