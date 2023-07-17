#ifndef BRAZZGUI_DIALOGHANDLING
#define BRAZZGUI_DIALOGHANDLING

#include <filesystem>

/*
 *  This namespace handles all OS specific operations for dialogs
 *  This includes showing OS provided dialogs (file select, OK/Cancel)
 */
namespace BrazzGUI::DialogHandling {
/*
 *  Shows an OK/Cancel dialog
 *
 *  @param title Window title for the dialog
 *  @param message Body message for the dialog
 *  @return true if user selects OK, false otherwise
 */
bool showOKCancel(std::string& title, std::string& message);

/*
 *  Shows a file save dialog
 *  This allows the user to select an existing file to overwrite or create a new
 * file
 *
 * @return Path to user selected file, blank if there was an error
 */
std::filesystem::path showFileSave();

/*
 *  Shows a file open dialog
 *  Allows the user to select only existing files
 *
 * @return Path to user selected file, blank if there was an error
 */
std::filesystem::path showFileOpen();
} // namespace BrazzGUI::DialogHandling

#endif