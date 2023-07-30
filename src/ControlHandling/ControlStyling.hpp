#ifndef CONTROL_STYLING
#define CONTROL_STYLING

#include "Color.hpp"
#include "ControlID.hpp"
#include "Font.hpp"

#include <string>

/*
 *   Namespace for OS specific operations for Controls
 *   ControlStyling includes everything that changes the appearance of a Control
 */
namespace BrazzGUI::ControlStyling {
/**
 * Makes the given Control visible
 *
 * @param id ID of the Control
 */
void show(const ControlID& id);

/**
 * Sets the x position of the given Control
 * Control positions are relative to their parents client area
 *
 * @param id ID of the Control
 * @param x New x position for the Control
 */
void setX(const ControlID& id, const int& x);

/**
 * Sets the y position of the given Control
 * Control positions are relative to their parents client area
 *
 * @param id ID of the Control
 * @param y New y position for the Control
 */
void setY(const ControlID& id, const int& y);

/**
 * Sets the width in pixels of the given Control
 *
 * @param id ID of the Control
 * @param width New width of the Control in pixels
 */
void setWidth(const ControlID& id, const int& width);

/**
 * Sets the height in pixels of the given Control
 *
 * @param id ID of the Control
 * @param height New height of the Control in pixels
 */
void setHeight(const ControlID& id, const int& height);

/**
 * Sets the text of the given Control
 *
 * @param id ID of the Control
 * @param text New text of the Control
 */
void setText(const ControlID& id, const std::string& text);

/**
 * Sets the font of the given Control
 *
 * @param id ID of the Control
 * @param font New font of the Control
 */
void setFont(const ControlID& id, const Font& font);

/**
 * Sets the check of the given Control
 * Only relevant for Checkboxes and RadioButtons
 *
 * @param id ID of the Control
 * @param check New check value of the Control
 */
void setCheck(const ControlID& id, const bool& check);

/**
 * Gets the check value of the given Control
 *
 * @param id ID of the Control
 * @return Check value of the Control (false if the Control has no check)
 */
bool isChecked(const ControlID& id);

/**
 * Get the x position of the given Control
 * Control positions are relevant to their parents client area
 *
 * @param id ID of the Control
 * @return X position of the Control
 */
int getX(const ControlID& id);

/**
 * Get the y position of the given Control
 * Control positions are relevant to their parents client area
 *
 * @param id ID of the Control
 * @return Y position of the Control
 */
int getY(const ControlID& id);

/**
 * Get the width of the given Control in pixels
 *
 * @param id ID of the Control
 * @return Width of the Control in pixels
 */
int getWidth(const ControlID& id);

/**
 * Get the height of the given Control in pixels
 *
 * @param id ID of the Control
 * @return Height of the Control in pixels
 */
int getHeight(const ControlID& id);

/**
 * Get the width of the given Controls client area in pixels
 *
 * @param id ID of the Control
 * @return Width of the Controls client area in pixels
 */
int getClientWidth(const ControlID);

/**
 * Get the height of the given Controls client area in pixels
 *
 * @param id ID of the Control
 * @return Height of the Controls client area in pixels
 */
int getClientHeight(const ControlID);

/**
 * Gets the height of a ComboBox Control
 *
 * @param id ID of the ComboBox
 * @return Height of the ComboBox in pixels, 0 if the Control is not a ComboBox
 */
int getComboBoxHeight(const ControlID& id);

/**
 * Gets the text of a Control
 *
 * @param id ID of the Control
 * @return Text of the Control
 */
std::string getText(const ControlID& id);

/**
 * Assigns a child Control to a parent
 *
 * @param parent Parent Control
 * @param child Child Control to be added
 */
void setChild(const ControlID& parent, const ControlID& child);

/**
 * Draws the background of a Control
 *
 * @param id ID of the Control
 * @param color Color of the background
 */
void drawBackground(const ControlID id, const Color color);

/**
 * Sets the background color of a Control
 *
 * @param id ID of the Control
 * @param color New background color of the Control
 */
void setBackgroundColor(const ControlID id, const Color color);

/**
 * Draws the text of a Control
 *
 * @param id ID of the Control
 * @param color Color of the text
 */
void drawText(const ControlID id, const Color color);

/**
 * Sets the text color of a Control
 *
 * @param id ID of the Control
 * @param color New text color of the Control
 */
void setTextColor(const ControlID id, const Color color);

/*
 *   TODO document
 */
void addTab(const ControlID id, std::string& tabName);

/*
 *   TODO document
 */
int getTabAreaWidth(const ControlID id);

/*
 *   TODO document
 */
int getTabAreaHeight(const ControlID id);

/*
 *   TODO document
 */
int getTabAreaX(const ControlID id);

/*
 *   TODO document
 */
int getTabAreaY(const ControlID id);

/*
 *   TODO document
 */
int getSelectedTabIndex(const ControlID id);

/*
 *   TODO document
 */
void setVisible(const ControlID id, const bool visible);

/**
 * TODO document
 */
void takeFocus(const ControlID id);

/**
 * TODO document
 */
void drawPixel(const ControlID id, int x, int y);

/**
 * TODO document
 */
void drawLine(const ControlID id, int x1, int y1, int x2, int y2);

/**
 * TODO document
 */
void drawRect(const ControlID id, int x1, int y1, int x2, int y2);

/**
 * TODO document
 */
void drawCircle(const ControlID id, int x1, int y1, double radius);

/**
 * TODO document
 */
void drawText(const ControlID id, int x1, int y1, int pt, const std::string& text);
} // namespace BrazzGUI::ControlStyling

#endif