#include "OKCancelDialog.hpp"

#include "DialogHandling/DialogHandling.hpp"

using namespace BrazzGUI;

bool OKCancelDialog::show(std::string& title, std::string& message) {
    return DialogHandling::showOKCancel(title, message);
}