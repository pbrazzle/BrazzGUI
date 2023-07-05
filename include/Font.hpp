#ifndef FONT
#define FONT

namespace BrazzGUI
{
/**
 * TODO document this class
*/
class Font
{
	private:
		int size;
		
	public:
		/**
		 * TODO document this function
		*/
		Font() = default;
		
		/**
		 * TODO document this function
		*/
		Font(const int&);
	
		/**
		 * TODO document this function
		*/
		int getSize() const;

		/**
		 * TODO document this function
		*/
		void setSize(const int&);
};
}

#endif