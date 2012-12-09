
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
		void addLayer();

		void setpos(double, double);



	protected:

	private:
		int i, maxLayer;
		vector3d m_pos[11];
		sf::Image backgroundimage[11];
		sf::Sprite backgroundsprite[22];
		sf::RenderWindow* window;


};

#endif
