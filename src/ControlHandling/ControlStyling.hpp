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
 *   Adds a tab to a TabGroup
 *
 * @param id ID of the TabGroup
 * @param tabName Display name for the tab
 */
void addTab(const ControlID id, std::string& tabName);

/*
 *   Gets the width of the tab area of a TabGroup
 *
 *  @param id ID of the TabGroup
 * @return Width in pixels of the TabGroups tab area
 */
int getTabAreaWidth(const ControlID id);

/*
 *   Gets the Height of the tab area of a TabGroup
 *
 *  @param id ID of the TabGroup
 * @return Height in pixels of the TabGroups tab area
 */
int getTabAreaHeight(const ControlID id);

/*
 *   Gets the X coordinate of the tab area of a TabGroup
 *  The coordinate is in relation to the TabGroups client area
 *
 * @param id ID of the TabGroup
 * @return X coordinate of the TabGroups tab area
 */
int getTabAreaX(const ControlID id);

/*
 *   Gets the Y coordinate of the tab area of a TabGroup
 *  The coordinate is in relation to the TabGroups client area
 *
 * @param id ID of the TabGroup
 * @return Y coordinate of the TabGroups tab area
 */
int getTabAreaY(const ControlID id);

/*
 *   Gets the index of the selected tab in a TabGroup
 *
 *  @param id ID of the TabGroup
 *  @return Index of the selected tab
 */
int getSelectedTabIndex(const ControlID id);

/*
 *   Sets a Controls visibility
 *
 * @param id ID of the Control
 * @param visible True if Control should be visible, false otherwise
 */
void setVisible(const ControlID id, const bool visible);

/**
 * Gives keyboard focus to a Control
 *
 * @param id ID of the Control
 */
void takeFocus(const ControlID id);

/**
 * Sets the drawing color for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param c New drawing color
 */
void setDrawColor(const ControlID id, const Color c);

/**
 * Draws a pixel for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param x X coordinate of the pixel
 * @param y Y coordinate of the pixel
 */
void drawPixel(const ControlID id, int x, int y);

/**
 * Draws a line for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param x1 X coordinate for the start of the line
 * @param y1 Y coordinate for the start of the line
 * @param x2 X coordinate for the end of the line
 * @param y2 Y coordinate for the end of the line
 */
void drawLine(const ControlID id, int x1, int y1, int x2, int y2);

/**
 * Draws a rectangle for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param x1 X coordinate of the top-left vertex
 * @param y1 Y coordinate of the top-left vertex
 * @param x2 X coordinate of the bottom-right vertex
 * @param y2 Y coordinate of the bottom-right vertex
 */
void drawRect(const ControlID id, int x1, int y1, int x2, int y2);

/**
 * Draws a circle for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param x1 X coordinate of the center
 * @param y1 Y coordinate of the center
 * @param radius Radius of the circle
 */
void drawCircle(const ControlID id, int x1, int y1, double radius);

/**
 * Draws text for a DrawPane
 *
 * @param id ID of the DrawPane
 * @param x1 X coordinate of the text
 * @param y1 Y coordinate of the text
 * @param pt Point size of the text
 * @param text Text to be drawn
 */
void drawText(const ControlID id, int x1, int y1, int pt,
              const std::string& text);
} // namespace BrazzGUI::ControlStyling

#endif