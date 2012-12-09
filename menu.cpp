#include "menu.hpp"

Menu::Menu( sf::RenderWindow* window)
{
    m_window = window;
    if (!menu_image.LoadFromFile("resource/sprites/menu_assets/menu_background.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		menu_sprite.SetImage(menu_image);
	}
    menu_sprite.SetX(0);
    menu_sprite.SetY(0);
}

Menu::~Menu()
{

}

bool Menu::update()
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
            if( Event.Type == sf::Event::KeyPressed)
            {
                if (Event.Key.Code == sf::Key::Escape)
                {
                    m_window->Close();
                    continuer = false;
                    break;
                }
            }
            if( Event.Type == sf::Event::MouseButtonPressed )
            {
                std::cout<< Event.MouseButton.X << "   " << Event.MouseButton.Y << std::endl;
                if( 557 > Event.MouseButton.X && 339 < Event.MouseButton.X
                   && 444 > Event.MouseButton.Y && 407 < Event.MouseButton.Y)
                   {
                       return true;
                   }
                else if( 557 > Event.MouseButton.X && 340 < Event.MouseButton.X
                   && 534 > Event.MouseButton.Y && 413 < Event.MouseButton.Y)
                   {
                       return false;
                   }
            }
        }
        m_window->Clear();
        sf::Shape rect = sf::Shape::Rectangle(0, 0, 1200, 600, sf::Color(255, 255, 255, 255));
        m_window->Draw(rect);
        m_window->Draw(menu_sprite);
        m_window->Display();

    }
    return false;
}
