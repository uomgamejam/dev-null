

#include <list>
#include "platform.hpp"
#include "character.hpp"
#include "background.hpp"

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class Super{

	public:
		Super(sf::RenderWindow* window);
		~Super();

		void update();
		int numP();
		Platform getP(int index);
		void addAcc( double x, double y);
		void display();

	protected:


	private:
		std::list<Platform*> platforms;
		Character player;
		Background background;
		int i;
		double lastTime;
		sf::RenderWindow* m_window;

		void createPlatforms();

		void removePlatforms();
		
		void shiftBackground();

        void movePlayer(double time);

        void moveAll(double time);

        sf::Clock clock;
};

#endif
