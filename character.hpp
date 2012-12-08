#ifndef __CHARACTER__HPP__
#define __CHARACTER__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Character
{

	public:
		Character( void* superclass, sf::RenderWindow* window);
		~Character();
        void update(double new_time);
        int getOffset();
        void display();
		const void* const thesuper;
		int collision(Platform* platform);
		void sx( int x );

	private:
		vector3d m_pos;
		vector3d m_vel;
		vector3d m_acc;
		vector3d m_size;
		double m_last_time;
		sf::RenderWindow* m_window;
		sf::Image m_image_running;
		sf::Sprite m_sprite_running;
		int m_offset;
};

#endif
