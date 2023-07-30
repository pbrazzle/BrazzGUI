#include "DrawPane.hpp"

#include "ControlHandling/ControlStyling.hpp"

using namespace BrazzGUI;

DrawPane::DrawPane() : BasicControl<ControlType::DrawPane>() { }

Color DrawPane::getColor() const { return drawColor; }

void DrawPane::setColor(const Color c) { drawColor = c; }

void DrawPane::drawPixel(int x, int y) {
    ControlStyling::drawPixel(getID(), x, y);
}

void DrawPane::drawLine(int x1, int y1, int x2, int y2) {
    ControlStyling::drawLine(getID(), x1, y1, x2, y2);
}

void DrawPane::drawRect(int x1, int y1, int x2, int y2) {
    ControlStyling::drawRect(getID(), x1, y1, x2, y2);
}

void DrawPane::drawCircle(int x1, int y1, double radius) {
    ControlStyling::drawCircle(getID(), x1, y1, radius);
}

void DrawPane::drawText(int x1, int y1, int pt, const std::string& text) {
    ControlStyling::drawText(getID(), x1, y1, pt, text)
}