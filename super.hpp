

#include <list>
#include "platform.hpp"
#include "character.hpp"

#ifndef __SUPER__HPP__
#define __SUPER__HPP__

class Super{

	public:
		Super();
		~Super();

		void update();

	protected:


	private:
		std::list<Platform> platforms;
		Character player();

		void display();

		void createPlatforms();

		void removePlatforms();

	        void movePlayer();

	        void moveAll();

	        int numP();

	        Platform getP(int index);
};

#endif
