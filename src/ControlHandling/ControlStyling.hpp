#ifndef CONTROL_STYLING
#define CONTROL_STYLING

#include "Color.hpp"
#include "ControlID.hpp"
#include "Font.hpp"

#include <string>

namespace BrazzGUI::ControlStyling {
/**
 * TODO document this function
 */
void show(const ControlID&);

/**
 * TODO document this function
 */
void setX(const ControlID&, const int&);

/**
 * TODO document this function
 */
void setY(const ControlID&, const int&);

/**
 * TODO document this function
 */
void setWidth(const ControlID&, const int&);

/**
 * TODO document this function
 */
void setHeight(const ControlID&, const int&);

/**
 * TODO document this function
 */
void setText(const ControlID&, const std::string&);

/**
 * TODO document this function
 */
void setFont(const ControlID&, const Font&);

/**
 * TODO document this function
 */
void setCheck(const ControlID&, const bool&);

/**
 * TODO document this function
 */
bool isChecked(const ControlID&);

/**
 * TODO document this function
 */
int getX(const ControlID&);

/**
 * TODO document this function
 */
int getY(const ControlID&);

/**
 * TODO document this function
 */
int getWidth(const ControlID&);

/**
 * TODO document this function
 */
int getHeight(const ControlID&);

/**
 * TODO document this function
 */
int getClientWidth(const ControlID);

/**
 * TODO document this function
 */
int getClientHeight(const ControlID);

/**
 * TODO document this function
 */
int getComboBoxHeight(const ControlID&);

/**
 * TODO document this function
 */
std::string getText(const ControlID&);

/**
 * TODO document this function
 */
void setChild(const ControlID& parent, const ControlID& child);

/**
 * TODO document this function
 */
void drawBackground(const ControlID, const Color);

/**
 * TODO document this function
 */
void setBackgroundColor(const ControlID, const Color);

/**
 * TODO document this function
 */
void drawText(const ControlID, const Color);

/**
 * TODO document this function
 */
void setTextColor(const ControlID, const Color);
} // namespace BrazzGUI::ControlStyling

#endif