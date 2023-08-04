#ifndef DRAW_PANE
#define DRAW_PANE

#include "Control.hpp"

#include <string>

namespace BrazzGUI {
/**
 * A DrawPane appears as a blank window, but it provides a PAINT Event to
 * perform drawing operations This allows for custom graphics in BrazzGUI
 * applications
 */
class DrawPane : public BasicControl<ControlType::DrawPane> {
    private:
    Color drawColor;

    public:
    /*
     *   Creates a DrawPane
     */
    DrawPane();

    /*
     *   Gets the drawing color for this DrawPane
     *
     *   @return Color this DrawPane is drawing with
     */
    Color getColor() const;

    /*
     *   Sets the drawing color for this DrawPane
     *
     *   @param c New drawing color
     */
    void setColor(const Color c);

    /*
     *   Draws a single pixel
     *
     *   @param x X coordinate to draw
     *   @param y Y coordinate to draw
     */
    void drawPixel(int x, int y);

    /*
     *   Draws a line
     *
     *   @param x1 Starting x coordinate
     *   @param y1 Starting y coordinate
     *   @param x2 Ending x coordinate
     *   @param y2 Ending y coordinate
     */
    void drawLine(int x1, int y1, int x2, int y2);

    /*
     *   Draws a rectangle
     *
     *   @param x1 X coordinate of the top-left vertex
     *   @param y1 Y coordinate of the top-left vertex
     *   @param x2 X coordinate of the bottom-right vertex
     *   @param y2 Y coordinate of the bottom-right vertex
     */
    void drawRect(int x1, int y1, int x2, int y2);

    /*
     *   Draws a circle
     *
     *  @param x1 X coordinate of the center
     *  @param y1 Y coordinate of the center
     *  @param radius Radius of the circle
     */
    void drawCircle(int x1, int y1, double radius);

    /*
     *   Draws text
     *
     * @param x1 X coordinate of the text
     * @param y1 Y coordinate of the text
     * @param pt Point size of the text
     * @param text Text to draw
     */
    void drawText(int x1, int y1, int pt, const std::string& text);
};
} // namespace BrazzGUI

#endif