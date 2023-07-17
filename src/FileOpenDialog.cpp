#include "FileOpenDialog.hpp"

#include "DialogHandling/DialogHandling.hpp"

using namespace BrazzGUI;

std::filesystem::path FileOpenDialog::show() {
    return DialogHandling::showFileOpen();
}