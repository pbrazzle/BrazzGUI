#ifndef CONTROL
#define CONTROL

#include "Color.hpp"
#include "ControlID.hpp"
#include "Font.hpp"

namespace BrazzGUI::ControlCreation {
enum class ControlType;
}

#include <string>

namespace BrazzGUI {
/**
 * TODO document this class
 */
class Control {
    private:
    Font font;
    Color backgroundColor;
    Color textColor;

    protected:
    ControlID id;

    public:
    /**
     * TODO document this function
     */
    Control(const ControlCreation::ControlType& type);

    /**
     * TODO document this function
     */
    virtual ~Control() = 0;

    /**
     * TODO document this function
     */
    void show();

    /**
     * TODO document this function
     */
    void setX(const int&);

    /**
     * TODO document this function
     */
    void setY(const int&);

    /**
     * TODO document this function
     */
    void setWidth(const int&);

    /**
     * TODO document this function
     */
    void setHeight(const int&);

    /**
     * TODO document this function
     */
    void setPosition(const int&, const int&, const int&, const int&);

    /**
     * TODO document this function
     */
    void setBackgroundColor(const Color);

    /**
     * TODO document this function
     */
    void setTextColor(const Color);

    /**
     * TODO document this function
     */
    void setText(const std::string&);

    /**
     * TODO document this function
     */
    void setFontSize(const int&);

    /**
     * TODO document this function
     */
    int getX() const;

    /**
     * TODO document this function
     */
    int getY() const;

    /**
     * TODO document this function
     */
    int getWidth() const;

    /**
     * TODO document this function
     */
    virtual int getHeight() const;

    /**
     * TODO document this function
     */
    int getFontSize() const;

    /**
     * TODO document this function
     */
    Color getBackgroundColor() const;

    /**
     * TODO document this function
     */
    Color getTextColor() const;

    /**
     * TODO document this function
     */
    std::string getText() const;

    /**
     * TODO document this function
     */
    ControlID getID() const;
};
} // namespace BrazzGUI

#endif