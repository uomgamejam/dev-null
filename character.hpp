
#ifndef __CHARACTER__HPP__
#define __CHARACTER__HPP__

class character{

	public:
		character(super* superclass) : thesuper(superclass);
		~character();
	
		const void* const thesuper;
		
	
	private:
		vector3d m_pos;
		vector3d m_vel;
		vector3d m_acc;
		double m_time_step;
};

#endif
