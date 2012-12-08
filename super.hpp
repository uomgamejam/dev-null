

#include <list>
#include "platform.hpp"
#include "character.hpp"

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class Super{

	public:
		Super(sf::RenderWindow* window);
		~Super();

		void update();
		int numP();
		Platform getP(int index);

		void display();

	protected:


	private:
		std::list<Platform> platforms;
		Character player;
		int i;
		sf::RenderWindow* m_window;

		void createPlatforms();

		void removePlatforms();

        void movePlayer();

        void moveAll();

        sf::Clock clock;
};

#endif
