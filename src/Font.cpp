#include "Font.hpp"

using namespace BrazzGUI;

Font::Font(const int& s) : size(s) { }

int Font::getSize() const { return size; }
void Font::setSize(const int& s) { size = s; } 