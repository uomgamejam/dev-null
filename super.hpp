

#include <list>

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class super{
	
	//public:
		public super();
		public ~super();
		
		void update();
		void 
		
		void update(){
		  movePlayer();
		  moveAll();
		  createPlatforms();
		  removePlatforms();
		  display();
		}
		
	protected:
	
	
	private:
		std::list<platform> platforms;
<<<<<<< HEAD
		character player;
=======
		character player = new character(); 
		
		void display(){
		  for (i = 0; i < platforms.size(); i ++)
		    platforms.at(i).display();
		  player.display();
		}
		
		void createPlatforms(){
		  if (platforms.back.gx() + platforms.back.gl() + 300 < 1200){
		    platform newPlatform = new platform();
		    platforms.push_back(newPlatform);
		  }
		}
		
		void removePlatforms(){
		  for (i = 0; i < platforms.size(); i ++){
		    if (platforms.at(i).x() + platforms.at(i).w() < 0){
		      platforms.erase(i);
		    }
		  }
		}
		
	        void movePlayer(){
	          //TODO
	        }
	        
	        	
	
>>>>>>> 5c0dd5f63a39f02b9eb09571fdfc8b7f802c267f
};

#endif
