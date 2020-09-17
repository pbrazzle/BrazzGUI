#include "Component.hpp"

//Getters
int Component::getX() const
{
	return x;
}

int Component::getY() const
{
	return y;
}

int Component::getWidth() const
{
	return width;
}
int Component::getHeight() const
{
	return height;
}

std::string Component::getText() const
{
	return text;
}

HANDLE Component::getHandle() const
{
	return handle;
}

//Setters
void Component::setX(int i)
{
	x = i;
}
void Component::setY(int i)
{
	y = i;
}

void Component::setWidth(int w)
{
	width = w;
}
void Component::setHeight(int h)
{
	height = h;
}
	 
void Component::setText(std::string t)
{
	text = t;
}

void Component::setHandle(HANDLE h)
{
	handle = h;
}