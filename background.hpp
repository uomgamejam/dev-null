
#include "vector3d.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#ifndef __BACKGROUND__HPP__
#define __BACKGROUND__HPP__

class Background
{
	
	public:
		Background(sf::RenderWindow*);
		Background(double, double);
		~Background();
		
		void update(double speed);
		void display();
		
		void setpos(double, double);
		
		
	protected:
	
	private:
		int i;
		vector3d m_pos;
		sf::Image backgroundimage[10];
		sf::Sprite backgroundsprite[20];
		sf::RenderWindow* window;
		
};

#endif
