#pragma once

#include "ControlID.hpp"
#include "Handlers/MenuHandler.hpp"

namespace BrazzGUI {

class Window;

/***
 * TODO document this class
 */
class Menu {
    private:
    ControlID parentID;
    std::unique_ptr<Handlers::MenuHandler> handler;

    public:
    Menu(const Window& parent);

    void addItem(const MenuItem&);
};
} // namespace BrazzGUI