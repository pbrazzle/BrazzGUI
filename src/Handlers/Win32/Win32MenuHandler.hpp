#pragma once

#include "Handlers/MenuHandler.hpp"

namespace BrazzGUI::Handlers::Win32 {
class Win32MenuHandler : public MenuHandler {
    public:
    /*
     *   TODO document this function
     */
    void addTopLevelItem(const Window& window, const MenuItem& item);

    /*
     *   TODO document this function
     */
    void addSubItem(const MenuItem& parent, const MenuItem& child);
};
} // namespace BrazzGUI::Handlers::Win32