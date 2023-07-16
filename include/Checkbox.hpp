#ifndef CHECKBOX
#define CHECKBOX

#include "Control.hpp"

namespace BrazzGUI
{
	/**
	 * The Checkbox Control class displays a check box in the BrazzApp GUI.
	 * Checkboxes will automatically toggle their check when clicked.
	*/
	class Checkbox : public Control
	{
		public:
			/**
			 * Creates a Checkbox
			*/
			Checkbox();
			
			/**
			 * Returns a Boolean value determining whether this Checkbox is checked
			 * 
			 * @return True is the Checkbox is checked, false otherwise
			*/
			bool isChecked();

			/**
			 * Sets the check value for this Checkbox
			 * 
			 * @param check If True, checks the Checkbox. Otherwise, removes the check.
			*/
			void setCheck(const bool& check);
	};
}

#endif