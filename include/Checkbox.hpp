#ifndef CHECKBOX
#define CHECKBOX

#include "Control.hpp"

namespace BrazzGUI
{
	/**
	 * TODO document this class
	*/
	class Checkbox : public Control
	{
		public:
			/**
			 * TODO document this function
			*/
			Checkbox();
			
			/**
			 * TODO document this function
			*/
			bool isChecked();

			/**
			 * TODO document this function
			*/
			void setCheck(const bool&);
	};
}

#endif