#ifndef BRAZZGUI_FILEOPENDIALOG
#define BRAZZGUI_FILEOPENDIALOG

#include <filesystem>

namespace BrazzGUI {

/*
 *   TODO document this class
 */
class FileOpenDialog {
    public:
    FileOpenDialog() = default;

    /*
     *   TODO document this function
     */
    std::filesystem::path show();
};

} // namespace BrazzGUI

#endif