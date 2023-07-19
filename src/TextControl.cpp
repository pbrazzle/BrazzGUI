#include "TextControl.hpp"

using namespace BrazzGUI;

template<ControlType type> TextControl<type>::TextControl() : Control(type) {}

template class TextControl<ControlType::TextArea>;
template class TextControl<ControlType::Textbox>;