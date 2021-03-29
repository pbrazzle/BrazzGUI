#include "TextBox.hpp"

TextBox::TextBox(int x, int y, int w, int h) : Control(x,y,w,h)
{
	setClassName("EDIT");
	setStyle(WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL);
	setText("");
}

TextBox::TextBox() : TextBox(0,0,100,100) { }

bool TextBox::getTextAsInt(int* i)
{
	std::string t = getText();
	if (t.length() == 0) return false;
	for (int j = 0; j < t.length(); j++)
		if (t[j] < 48 || t[j] > 57) return false;
		
	*i = std::stoi(t);
	return true;
}

bool TextBox::getTextAsDouble(double* d)
{
	std::string t = getText();
	if (t.length() == 0) return false;
	for (int j = 0; j < t.length(); j++)
		if (t[j] < 46 || t[j] > 57 && t[j] != 47) return false;
		
	*d = std::stod(t);
	return true;
}

void TextBox::setFontSize(int s)
{
	HFONT font = CreateFontA(
		s, s,
		0,0,0,
		false,false,false,
		DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY,
		VARIABLE_PITCH | FF_SWISS,
		"Arial");
	SendMessage(getHandle(), WM_SETFONT, (WPARAM) font, true);
}