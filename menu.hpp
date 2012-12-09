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
		sf::Image menu_image, hand1_image, hand2_image, stickman_image;
		sf::Sprite menu_sprite, hand1_sprite, hand2_sprite, stickman_sprite;
		int m_frame1_x, m_frame1_y, m_frame;
		sf::Clock clock;
		sf::Clock clock1;
		double last_time, last_time1;


};

#endif
