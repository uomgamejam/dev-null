#ifndef __MENU__HPP__
#define __MENU__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "vector3d.hpp"

class Menu
{
	public:
		Menu( sf::RenderWindow* window);
		~Menu();
        bool update();

	private:
		vector3d m_pos;
		sf::RenderWindow* m_window;
		sf::Image menu_image;
		sf::Sprite menu_sprite;


};

#endif
