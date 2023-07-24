#ifndef MENU_ITEM
#define MENU_ITEM

#include "Handlers/MenuHandler.hpp"

#include <memory>

namespace BrazzGUI {
/**
 * A Control that can only be added as a child to a Menu
 * This class is not yet implemented, but it will be in v0.1
 */
class MenuItem {

    private:
    std::unique_ptr<BrazzGUI::Handlers::MenuHandler> handler;

    public:
    /**
     * TODO document this function
     */
    MenuItem();

    /*
     *   TODO document this function
     */
    void addSubItem(const MenuItem& item);
};
} // namespace BrazzGUI

#endif