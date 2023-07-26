#ifndef MENU_ITEM
#define MENU_ITEM

#include "ControlID.hpp"
#include "Handlers/MenuHandler.hpp"

#include <memory>
#include <string>

namespace BrazzGUI {
/**
 * A Control that can only be added as a child to a Menu
 * This class is not yet implemented, but it will be in v0.1
 */
class MenuItem {

    private:
    std::unique_ptr<BrazzGUI::Handlers::MenuHandler> handler;
    ControlID id;
    std::string text;

    public:
    /**
     * TODO document this function
     */
    MenuItem();

    MenuItem(const std::string& t);

    /*
     *   TODO document this function
     */
    void addSubItem(const MenuItem& item);

    /**
     * TODO document this function
     */
    ControlID getID() const;

    std::string getText() const;

    void setText(const std::string& t);
};
} // namespace BrazzGUI

#endif