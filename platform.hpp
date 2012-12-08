
#include "vector3d.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#ifndef __PLATFORM__HPP__
#define __PLATFORM__HPP__

class Platform
{

	public:
		Platform(sf::RenderWindow);
		Platform(double, double, double, double, double, double);
		~Platform();
		
		void update();
		void display();
		
		void setpos(double, double);
		void setsize(double, double);
		void setvel(double, double);
	
	protected:
	
	
	private:
		vector3d m_pos;
		vector3d m_size;
		vector3d m_vel;
		
		sf::Image platformimage;
		sf::Sprite platformsprite;
		sf::RenderWindow* window;
};

#endif
