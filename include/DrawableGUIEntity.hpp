#ifndef DRAWABLEGUIENTITY
#define DRAWABLEGUIENTITY

#include "GUIEntity.hpp"

class DrawableGUIEntity : public GUIEntity
{
	private:
		friend class Brush;
	
		HDC buffer;
		
		virtual void initialize();
		
	protected:
		void resetBuffer();
		
	public:
		DrawableGUIEntity();
		DrawableGUIEntity(int,int,int,int);
	
		virtual ~DrawableGUIEntity();
		
		void paint();
		void setWidth(unsigned int);
		void setHeight(unsigned int);

};

#endif