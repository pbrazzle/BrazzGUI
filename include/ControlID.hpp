#ifndef CONTROL_ID
#define CONTROL_ID

namespace BrazzGUI
{
	class ControlID
	{
		private:
			int id;
		
		public:
			ControlID(const int&);
		
			bool operator<(const ControlID& rhs) const;
		
			int getValue() const;
	};
}

#endif