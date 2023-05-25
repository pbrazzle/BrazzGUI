#ifndef FONT
#define FONT

namespace BrazzGUI
{
	class Font
	{
		private:
			int size;
			
		public:
			Font() = default;
			Font(const int&);
		
			int getSize() const;
			void setSize(const int&);
	};
}

#endif