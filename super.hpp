

#include <list>

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class super{
	
	public:
		super();
		~super();
		
		void update(){
		  //TODO
		}
		
		void display(){
		  //TODO
		}
		
	protected:
	
	private:
		std::list<platform> platforms;
		character player = new character(); 
		
		void createPlatforms(){
		  //TODO
		}
		
		void removePlatforms(){
		  //TODO
		}
		
	        void movePlayer(){
	          //TODO
	        }
	        
	        	
	
};

#endif
