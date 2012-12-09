
#include "vector3d.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#ifndef __PLATFORM__HPP__
#define __PLATFORM__HPP__

class Wall
{

	public:
		Wall(sf::RenderWindow*);
		Wall(double, double, double, double);
		~Wall();

		void update(double);
		void display();


		// Set
		void setpos(double, double);
		void setsize(double, double);

		// Get
		const vector3d& pos();
		const vector3d& size();


	protected:


	private:
		vector3d m_pos;
		vector3d m_size;

		sf::Image wallimage;
		sf::Sprite wallsprite;
		sf::RenderWindow* window;
};

#endif
