/*
* Event class
* Contains information about user input events
*/

#ifndef EVENT
#define EVENT

#include <vector>

#define MOUSE_LEFT_DOWN 0
#define MOUSE_LEFT_UP 1
#define MOUSE_RIGHT_DOWN 2
#define MOUSE_RIGHT_UP 3
#define ARROW_UP_PRESS 4
#define ARROW_UP_RELEASE 5
#define ARROW_DOWN_PRESS 6
#define ARROW_DOWN_RELEASE 7
#define ARROW_LEFT_PRESS 8
#define ARROW_LEFT_RELEASE 9
#define ARROW_RIGHT_PRESS 10
#define ARROW_RIGHT_RELEASE 11
#define C_KEY_PRESS 12

class Event {
	
	private:
	
		unsigned int id, x, y;
	
	public:
		
		Event(unsigned int, unsigned int, unsigned int);
		std::vector<unsigned int> getLocation();
		unsigned int getID();
	
};

#endif