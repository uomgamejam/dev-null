#include "gameOver.hpp"

GameOver::GameOver( sf::RenderWindow* window)
{
    m_window = window;
    if (!over_image.LoadFromFile("resource/sprites/game_over_assets/game_over_overlay.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		over_sprite.SetImage(over_image);
	}
    over_sprite.SetX(0);
    over_sprite.SetY(0);
}

GameOver::~GameOver()
{

}

bool GameOver::update()
{
    bool continuer = true;
    while( continuer)
    {
        sf::Event Event;
        while (m_window->GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
            {
                m_window->Close();
                continuer = false;
                break;
            }
            else if( Event.Type == sf::Event::KeyPressed)
            {
                if (Event.Key.Code == sf::Key::Escape)
                {
                    m_window->Close();
                    continuer = false;
                    break;
                }
            }
            else
            {
                return true;
            }
        }
        m_window->Clear();
        sf::Shape rect = sf::Shape::Rectangle(0, 0, 1200, 600, sf::Color(255, 255, 255, 255));
        m_window->Draw(rect);
        m_window->Draw(over_sprite);
        m_window->Display();

    }
    return false;
}
