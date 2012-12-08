

#include <list>
#include "platform.hpp"
#include "Character.hpp"

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class super{
	
	public:
		super();
		~super();
		
		void update();
		
	protected:
	
	
	private:
		std::list<platform> platforms;
		character player(); 
		
		void display();
		
		void createPlatforms();
		
		void removePlatforms();
		
	        void movePlayer();
	        
	        void moveAll();
};

#endif
