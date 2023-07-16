#ifndef BRAZZGUI_FILESELECTDIALOG
#define BRAZZGUI_FILESELECTDIALOG

#include <filesystem>

namespace BrazzGUI {

/*
 * The FileSaveDialog selects a filepath for the BrazzGUI application to save
 * data to
 * Unlike the FileOpenDialog, the selected file does not have to already exist
 */
class FileSaveDialog {
    public:
    FileSaveDialog() = default;

    /*
     * Shows the dialog, and returns the filepath to the selected file
     *
     * @return Path to the selected file
     */
    std::filesystem::path show();
};

} // namespace BrazzGUI

#endif