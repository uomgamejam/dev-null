
#include "vector3d.hpp"

#ifndef __PLATFORM__HPP__
#define __PLATFORM__HPP__

class platform()
{

	public:
		platform();
		platform(double, double, double, double, double, double);
		~platform();
		
		void update();
		void draw();
		
		void setpos(double, double);
		void setsize(double, double);
		void setvel(double, double);
	
	protected:
	
	
	private:
		vector3d m_pos;
		vector3d m_size;
		vector3d m_vel;
};

#endif
