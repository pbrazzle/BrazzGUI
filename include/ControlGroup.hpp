#ifndef CONTROLGROUP
#define CONTROLGROUP

#include "DrawableGUIEntity.hpp"

class ControlGroup : public DrawableGUIEntity
{
	private:
		void initialize();

	public:
		ControlGroup();
		ControlGroup(int,int,int,int);
		
		void addChild(GUIEntity&);
};

#endif