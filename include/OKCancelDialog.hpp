#ifndef BRAZZGUI_OKCANCEL
#define BRAZZGUI_OKCANCEL

#include <string>

namespace BrazzGUI {

/*
 *  The OKCancelDialog prompts a user with a simple message
 *  The user can then click one or more response buttons (OK/Cancel)
 */
class OKCancelDialog {
    public:
    OKCancelDialog() = default;

    /*
     *   Shows the dialog
     *
     * @param title Text to display the dialog window title
     * @param message Message to display in the dialog body
     * @return false if user selects cancel, true otherwise
     */
    bool show(std::string& title, std::string& message);
};

} // namespace BrazzGUI

#endif