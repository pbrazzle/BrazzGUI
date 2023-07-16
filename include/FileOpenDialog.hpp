#ifndef BRAZZGUI_FILEOPENDIALOG
#define BRAZZGUI_FILEOPENDIALOG

#include <filesystem>

namespace BrazzGUI {

/*
 * The FileOpenDialog is used to select existing files in a BrazzGUI
 * application
 */
class FileOpenDialog {
    public:
    FileOpenDialog() = default;

    /*
     *  Shows the dialog and returns the selected file
     *
     *  @return Path to the selected file
     */
    std::filesystem::path show();
};

} // namespace BrazzGUI

#endif