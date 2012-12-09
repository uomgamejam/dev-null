#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include "super.hpp"
#include "menu.hpp"
#include "gameOver.hpp"

const unsigned int FRAMES_PER_SEC = 40;


void printText(int x, int y, std::string content, int size, sf::RenderWindow* window, Super* super);
	

int main()
{
	
    std::ifstream fluxConfig("./resource/configuration.txt" );
    if ( fluxConfig)
    {
        int widthW, heightW;

        fluxConfig >> widthW;
        fluxConfig >> heightW;

        sf::RenderWindow window(sf::VideoMode(widthW, heightW, 32), "Game");
       //  window.UseVerticalSync(true);

        window.SetFramerateLimit(FRAMES_PER_SEC);

        sf::Music gameSong;
        sf::Music jumpSound;
        gameSong.OpenFromFile("resource/sounds/music_gameplay.wav");
        jumpSound.OpenFromFile("resource/sounds/jump.wav");
        gameSong.SetLoop(true);
        gameSong.Play();

        bool keep = true;
		while(keep){
		    Menu menu(&window);
		    bool play = menu.update();
            keep = play;

            if( keep)
            {
				    Super super(&window);
                    while(play){
                        sf::Event Event;
                        while (window.GetEvent(Event))
                        {
                            if (Event.Type == sf::Event::Closed)
                            {
                                window.Close();
                                play = false;
                                keep = false;
                                break;
                            }
                            if( Event.Type == sf::Event::KeyPressed)
                            {
                                if (Event.Key.Code == sf::Key::Escape)
                                {
                                    window.Close();
									play = false;
									keep = false;
                                    break;
                                }
                                else if ( Event.Key.Code == sf::Key::Up )
                                {
                                    super.addVel(0, -1750);
                                    jumpSound.Play();
                                }
                                else if ( Event.Key.Code == sf::Key::Down )
                                {
                                    super.attaq();
                                }

                            }
                        }
                        
                  
                        super.update();
                        window.Clear();     
                        
                        
                        sf::Shape rect = sf::Shape::Rectangle(0, 0, 1200, 600, sf::Color(255, 255, 255, 255));
                        window.Draw(rect);
                        super.display();
                        std::stringstream converter;
						converter << "  Time: ";
						converter << (unsigned long)super.score;
						std::string scoretext = converter.str();
						printText(20, 20, scoretext, 16, &window, &super);
                        std::stringstream converter2;
						converter2 << "Tokens: ";
						converter2 << (unsigned long)super.tokens;
						scoretext = converter2.str();
						printText(20, 60, scoretext, 16, &window, &super);

                        window.Display();
                        if ( super.stop == true )
                            play = false;
                    }


                if( keep )
                {
                    GameOver gameOver(&window);
                    keep = gameOver.update();
                }
            }
            

        }
    }
    else
    {
        std::cout << " Could not open the file configuration.txt" << std::endl;
    }

    return 0;
}

void printText(int x, int y, std::string content, int size, sf::RenderWindow* window, Super* super){
	
	sf::String text(content, super->textFont, size);
	
	text.SetColor(sf::Color(0, 0, 0));
	text.SetRotation(0.0f);
	text.SetScale(2.0f, 2.0f);
	text.Move(x, y);
	
	window->Draw(text);
}
