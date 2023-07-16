#ifndef BRAZZGUI_OKCANCEL
#define BRAZZGUI_OKCANCEL

#include <string>

namespace BrazzGUI {

/*
 *   TODO document this class
 */
class OKCancelDialog {
    public:
    OKCancelDialog() = default;

    /*
     *   TODO document this function
     */
    bool show(std::string &title, std::string &message);
};

} // namespace BrazzGUI

#endif