

#include <list>
#include "platform.hpp"

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class super{
	
	public:
		super();
		~super();
		
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
	          player.move();
	        }
	        
	        void moveAll(){
	          for (i = 0; i < platforms.size(); i ++)
	            platforms.at(i).sx(platforms.at(i).x() - player.vel.x());
	        }
};

#endif
