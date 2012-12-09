

#include <list>
#include "platform.hpp"
#include "character.hpp"
#include "background.hpp"
#include "upgrade.hpp"
#include <vector>
#include <SFML/Audio.hpp>

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class Super{

	public:
		Super(sf::RenderWindow* window);
		~Super();

		void update();
		int numP();
		Platform getP(int index);
		int numU();
		Upgrade getU(int index);
		void deleteU(int index);
		void addVel( double x, double y);
		void display();
		void addBackground();

	protected:


	private:
		std::list<Platform*> platforms;
		std::vector<Upgrade*> upgrades;
		Character player;
		Background background;
		int i;
		double lastTime;
		sf::RenderWindow* m_window;
		sf::Music mountainFX;

		void createPlatforms();

		void removePlatforms();

		void shiftBackground();

        void movePlayer(double time);

        void moveAll(double time);

        sf::Clock clock;
};

#endif
