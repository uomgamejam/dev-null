#include "menu.hpp"

Menu::Menu( sf::RenderWindow* window)
{
    m_window = window;
    if (!menu_image.LoadFromFile("resource/sprites/menu_assets/menu_background.png")
        || !hand1_image.LoadFromFile("resource/sprites/menu_assets/left_hand_static.png")
        || !hand2_image.LoadFromFile("resource/sprites/menu_assets/right_hand_sheet.png")
        || !stickman_image.LoadFromFile("resource/sprites/menu_assets/stickman_sheet.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		menu_sprite.SetImage(menu_image);
		hand1_sprite.SetImage(hand1_image);
		hand2_sprite.SetImage(hand2_image);
		stickman_sprite.SetImage(stickman_image);
	}
    menu_sprite.SetX(0);
    menu_sprite.SetY(0);
    hand1_sprite.SetX(0);
    hand1_sprite.SetY(225);
    hand2_sprite.SetX(822);
    hand2_sprite.SetY(218);
    stickman_sprite.SetX(523);
    stickman_sprite.SetY(180);
    m_frame = 0;
    m_frame1_x = 0;
    m_frame1_y = 0;
    clock.Reset();
    clock1.Reset();
    last_time = 0;
    last_time1 = 0;
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
        if( clock.GetElapsedTime() - last_time > 0.1)
        {
            m_frame1_x++;
            if( m_frame1_y == 4 && m_frame1_x == 2 )
            {
                m_frame1_y = 0;
                m_frame1_x = 0;
            }
            else if( m_frame1_x > 5 )
            {
                m_frame1_x = 0;
                m_frame1_y++;
            }
            last_time = clock.GetElapsedTime();
        }
        if( clock1.GetElapsedTime() - last_time1 > 0.1)
        {
            m_frame++;
            if( m_frame > 15 )
                m_frame = 0;
            last_time1 = clock1.GetElapsedTime();
        }
        sf::Shape rect = sf::Shape::Rectangle(0, 0, 1200, 600, sf::Color(255, 255, 255, 255));
        hand2_sprite.SetSubRect(sf::IntRect(m_frame1_x * 378, m_frame1_y * 386, m_frame1_x * 378 + 378, m_frame1_y * 386 + 386));
        stickman_sprite.SetSubRect(sf::IntRect(m_frame * 152, 0, m_frame*152+152, 154));
        m_window->Draw(rect);
        m_window->Draw(menu_sprite);
        m_window->Draw(hand1_sprite);
        m_window->Draw(hand2_sprite);
        m_window->Draw(stickman_sprite);
        m_window->Display();

    }
    return false;
}
