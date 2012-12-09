
#include "vector3d.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#ifndef __SHURIKEN__HPP__
#define __SHURIKEN__HPP__
#include "wall.hpp"

class Shuriken
{

	public:
		Shuriken(void* superclass, sf::RenderWindow*);
		~Shuriken();

		void update(double);
		void display();

        bool simpleCollision(Wall wall, double offsety);

		// Set
		void setpos(double, double);
		void setsize(double, double);

		// Get
		const vector3d& pos();
		const vector3d& size();

		const void* const thesuper;


	protected:


	private:
		vector3d m_pos;
		vector3d m_vel;
		vector3d m_size;

		sf::Image shurikenimage;
		sf::Sprite shurikensprite;
		sf::RenderWindow* window;

		double lastTime;
		bool first;
};

#endif

