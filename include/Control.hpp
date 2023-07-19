#ifndef CONTROL
#define CONTROL

#include "Color.hpp"
#include "ControlID.hpp"
#include "Font.hpp"

#include <string>

namespace BrazzGUI {
/**
 * Enum for all types of Controls
 */
enum class ControlType {
    Window,
    Button,
    Label,
    Textbox,
    TextArea,
    DrawPane,
    Checkbox,
    RadioButton,
    RadioButtonGroup,
    ComboBox,
    Panel
};

/**
 * Every visible component in BrazzGUI is a Control
 * Controls handle Events created by the user in a BrazzGUI application
 * (clicks, text changes)
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
     * Creates a Control
     *
     * @param type Type of Control to create
     */
    Control(const ControlType& type);

    /**
     * Virtual desctructor
     */
    virtual ~Control() = 0;

    /**
     * Makes the Control visible
     */
    void show();

    /**
     * Sets the x position for this Control
     * A Controls position is relative to its parent window
     *
     * @param x New x position
     */
    void setX(const int& x);

    /**
     * Sets the y position for this Control
     * A Controls position is relative to its parent window
     *
     * @param y New y position
     */
    void setY(const int& y);

    /**
     * Sets the width for this Control in pixels
     *
     * @param width New width in pixels
     */
    void setWidth(const int& width);

    /**
     * Sets the height for this Control in pixels
     *
     * @param height New width in pixels
     */
    void setHeight(const int& height);

    /**
     * Sets the position for this Control
     *
     * @param x New x position
     * @param y New y position
     * @param width New width in pixels
     * @param height New height in pixels
     */
    void setPosition(const int& x, const int& y, const int& width,
                     const int& height);

    /**
     * Sets the background color for this Control
     * Some Controls cannot control their colors
     *
     * @param color New background color
     */
    void setBackgroundColor(const Color color);

    /**
     * Sets the text color for this Control
     * Some Controls cannot control their colors
     *
     * @param color New text color
     */
    void setTextColor(const Color color);

    /**
     * Sets the text shown for this Control
     * For example, a Buttons text is displayed in the middle of its client
     * window
     *
     * @param text New shown text
     */
    void setText(const std::string& text);

    /**
     * Sets the font size for this Controls text
     * Not all Controls can control their font size
     * Some Controls do not show text at all
     *
     * @param size New font size
     */
    void setFontSize(const int& size);

    /**
     * Gets the x position for this Control
     * A Controls position is relative to its parents client window
     *
     * @return X position for this Control
     */
    int getX() const;

    /**
     * Gets the y position for this Control
     * A Controls position is relative to its parents client window
     *
     * @return Y position for this Control
     */
    int getY() const;

    /**
     * Gets the width for this Control in pixels
     *
     * @return Width for this Control in pixels
     */
    int getWidth() const;

    /**
     * Gets the height for this Control in pixels
     *
     * @return Height for this Control in pixels
     */
    virtual int getHeight() const;

    /**
     * Gets the font size for this Controls text
     *
     * @return Font size for this Control
     */
    int getFontSize() const;

    /**
     * Gets the background color for this Control
     *
     * @return Background color for this Control
     */
    Color getBackgroundColor() const;

    /**
     * Gets the text color for this Control
     *
     * @return Text color for this Control
     */
    Color getTextColor() const;

    /**
     * Gets the text shown for this Control
     *
     * @return Text for this Control
     */
    std::string getText() const;

    /**
     * Gets the ID for this Control
     *
     * @return This Controls ID
     */
    ControlID getID() const;
};

template<ControlType type> class BasicControl : public Control {
    public:
    BasicControl();
};

} // namespace BrazzGUI

#endif