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
            sf::Event Event;
            while (window.GetEvent(Event))
            {
                if (Event.Type == sf::Event::Closed)
                {
                    window.Close();
                    break;
                }
                if( Event.Type == sf::Event::KeyPressed)
                {
                    if (Event.Key.Code == sf::Key::Escape)
                    {
                        window.Close();
                        break;
                    }
                    else if ( Event.Key.Code == sf::Key::Up )
                    {
                        super.addAcc(0, -25000);
                    }
                }
            }
			super.update();
			window.Clear();
			sf::Shape rect = sf::Shape::Rectangle(0, 0, 1200, 600, sf::Color(255, 255, 255, 255));
			window.Draw(rect);
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
