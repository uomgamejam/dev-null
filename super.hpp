

#include <list>
#include "platform.hpp"
#include "character.hpp"
#include "background.hpp"
#include "upgrade.hpp"
#include <vector>
#include <SFML/Audio.hpp>
#include "wall.hpp"
#include "shuriken.hpp"

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
		int numW();
		Wall getW(int index);
		void deleteW(int index);
		bool addVel( double x, double y);
		void display();
		void addBackground();
		void createWall();
		void deleteWall();
		void attaq();
		void deleteS(int index);
		bool stop;
		sf::Font textFont;

		
		double score;
		int tokens;

	protected:


	private:
		std::list<Platform*> platforms;
		std::vector<Upgrade*> upgrades;
		std::vector<Wall*> walls;
		std::vector<Shuriken*> shurikens;
		Character player;
		Background background;
		int i;
		double lastTime;
		sf::RenderWindow* m_window;
		int distance_wall;
		int distance_last_wall;

		void createPlatforms();

		void removePlatforms();

		void shiftBackground();

        void movePlayer(double time);

        void moveAll(double time);

        sf::Clock clock;

};

#endif
