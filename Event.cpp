#include "Event.hpp"

Event::Event(unsigned int i, unsigned int a, unsigned int b)
{
	id = i;
	x = a;
	y = b;
}

unsigned int Event::getID() { return id; }

std::vector<unsigned int> Event::getLocation()
{
	std::vector<unsigned int> v = {x,y};
	return v;
}