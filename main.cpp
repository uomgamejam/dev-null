#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "super.hpp"

const unsigned int FRAMES_PER_SEC = 40;
static unsigned long framecounter = 0;

int main()
{
    std::ifstream fluxConfig("./resource/configuration.txt" );
    if ( fluxConfig)
    {
        int widthW, heightW;

        fluxConfig >> widthW;
        fluxConfig >> heightW;

        sf::RenderWindow window(sf::VideoMode(widthW, heightW, 32), "Game");
		Super super = Super(&window);
        window.UseVerticalSync(true);

        window.SetFramerateLimit(FRAMES_PER_SEC);

		while(1){
			// std::cout << framecounter ++ << std::endl;
			super.update();
			super.display();
			window.Display();
		}
    }
    else
    {
        std::cout << " Could not open the file configuration.txt" << std::endl;
    }

    return 0;
}
