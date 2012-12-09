#ifndef __CHARACTER__HPP__
#define __CHARACTER__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "platform.hpp"


class Character
{

	public:
		Character( void* superclass, sf::RenderWindow* window);
		~Character();
        void update(double new_time);
        int offset();
        void display();
		const void* const thesuper;
		int collision(Platform platform);
		void sx( int x );
		void addAcc( double x, double y);
		const vector3d& pos()
		{
		    return m_pos;
		}
		bool onPlatform();

	private:
		vector3d m_pos;
		vector3d m_vel;
		vector3d m_acc;
		vector3d m_size;
		double m_last_time;
		sf::RenderWindow* m_window;
		sf::Image m_image_running;
		sf::Sprite m_sprite_running;
		double m_offset;
		double m_frame, m_last_frame_time, m_frame_time;
		double x,y,z;
};

#endif
