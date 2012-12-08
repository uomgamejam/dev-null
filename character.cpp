#include "character.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

Character::Character(super* superclass, sf::RenderWindow* window) : thesuper(superclass), m_acc(0, -9.81, 0), m_vel(5, 0, 0), m_pos(5, 5, 0)
{
    m_window = window;
    m_image_running.LoadFromFile("resource/sprites/run_cycle_sheet.png");
    m_sprite_running.SetImage(m_image_running);
}

Character::~Character()
{
}

void Character::display()
{
    m_sprite_running.SetX(m_pos.x());
    m_sprite_running.SetY(m_pos.y());
    m_window->Draw(m_sprite_running);
}

void Character::update(double new_time)
{
    double step_time = new_time - m_last_time;
    m_vel.sx(m_vel.x() + m_acc.x() * (int)step_time );
    m_vel.sx(m_vel.y() + m_acc.y() * (int)step_time );
    for( int i = 0; i < thesuper.getNumberPlatform(); i ++)
    {
        collision
    }
}

int Character::offset()
{
    return m_offsett;
}

Direction Character::collision(Platform* platform);
{

}

