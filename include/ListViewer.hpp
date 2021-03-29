#ifndef LISTVIEWER
#define LISTVIEWER

#include "Control.hpp"

#include <string>
#include <vector>

class ListViewer : public Control
{
	private:
		std::vector<std::string> items;
	
		void initialize();
		
	public:
		ListViewer();
		ListViewer(int,int,int,int);
		
		void addItem(std::string s);
		std::string getSelectedItem();
		int getSelectedIndex();
		void removeSelectedItem();
		void removeItem(int);
};

#endif