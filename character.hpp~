#ifndef __CHARACTER__HPP__
#define __CHARACTER__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "platform.hpp"
#include "upgrade.hpp"
#include "wall.hpp"


class Character
{

	public:
		Character( void* superclass, sf::RenderWindow* window);
		~Character();
        void update(double new_time);
        int offset();
        void display();
		const void* const thesuper;
		int collision(Platform platform, double offsety);
		void sx( int x );
		void addVel( double x, double y);
		bool simpleCollision(Upgrade upgrade);
		bool simpleCollision(Wall wall);
		bool attaq();
		const vector3d& pos()
		{
		    return m_pos;
		}
		bool onPlatform();
		double score(){ return scoreTime; }
		int tokens(){ return nbTokens; }

	private:
		vector3d m_pos;
		vector3d m_vel;
		vector3d m_acc;
		vector3d m_size;
		double m_last_time;
		sf::RenderWindow* m_window;
		sf::Image m_image_running;
		sf::Sprite m_sprite_running;
		sf::Image m_image_upgrades[3];
		sf::Sprite m_sprite_upgrade[3];
		bool upgrade[3];
		double m_offset;
		double m_frame, m_last_frame_time, m_frame_time;
		double x,y,z;
		double scoreTime;
		int nbTokens;
		int nbShurikan;

};

#endif
