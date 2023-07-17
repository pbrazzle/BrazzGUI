#include "FileSaveDialog.hpp"

#include "DialogHandling/DialogHandling.hpp"

using namespace BrazzGUI;

std::filesystem::path FileSaveDialog::show() {
    return DialogHandling::showFileSave();
}