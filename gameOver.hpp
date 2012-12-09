#ifndef __GAMEOVER__HPP__
#define __GAMEOVER__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "vector3d.hpp"

class GameOver
{
	public:
		GameOver( sf::RenderWindow* window);
		~GameOver();
        bool update();

	private:
		vector3d m_pos;
		sf::RenderWindow* m_window;
		sf::Image over_image;
		sf::Sprite over_sprite;


};

#endif
