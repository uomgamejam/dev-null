#include "character.hpp"
#include "super.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

Character::Character(void* superclass, sf::RenderWindow* window) : thesuper(superclass), m_acc(0, -9.81, 0), m_vel(5, 0, 0), m_pos(5, 5, 0)
{
    m_window = window;
    if( !m_image_running.LoadFromFile("resource/sprites/run_cycle_sheet.png") )
        std::cout<< "error" << std::endl;
   else
        m_sprite_running.SetImage(m_image_running);
}

Character::~Character()
{
}

void Character::display()
{   /*
    m_sprite_running.SetX(m_pos.x());
    m_sprite_running.SetY(m_pos.y());*/
    m_window->Draw(m_sprite_running);
}

void Character::update(double new_time)
{
    double step_time = new_time - m_last_time;
    m_vel.sx(m_vel.x() + m_acc.x() * (int)step_time );
    m_vel.sx(m_vel.y() + m_acc.y() * (int)step_time );
    for( int i = 0; i < ((Super*)thesuper)->numP(); i ++)
    {
        Platform platform = ((Super*)thesuper)->getP(i);
        m_pos.sy(m_pos.y() + collision(platform));
    }
}

void Character::sx( int x )
{
    m_pos.sx(x);
}

int Character::offset()
{
    return m_offset;
}

int Character::collision(Platform platform)
{
    if( ( m_pos.x() + m_size.x() < platform.pos().x()
       || m_pos.y() + m_size.y() < platform.pos().y()
       || m_pos.x() > platform.pos().x() + platform.size().x()
       || m_pos.y() > platform.pos().y() + platform.size().y() )
       && m_vel.y() < 0 )
    {
        return platform.pos().y() - m_pos.y();
    }

}

