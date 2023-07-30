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
class DrawPane : public BasicControl<ControlType::DrawPane>
{
    private:
        Color drawColor;

    public:
    /*
    *   TODO document
    */
    DrawPane();
    
    /*
    *   TODO document
    */
    Color getColor() const;

    /*
    *   TODO document
    */
    void setColor(const Color c);

    /*
    *   TODO document
    */
    void drawPixel(int x, int y);

    /*
    *   TODO document
    */
    void drawLine(int x1, int y1, int x2, int y2);

    /*
    *   TODO document
    */
    void drawRect(int x1, int y1, int x2, int y2);

    /*
    *   TODO document
    */
    void drawCircle(int x1, int y1, double radius);

    /*
    *   TODO document
    */
    void drawText(int x1, int y1, int pt, const std::string& text);
};
} // namespace BrazzGUI

#endif