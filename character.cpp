#include "character.hpp"
#include "super.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

Character::Character(void* superclass, sf::RenderWindow* window) : thesuper(superclass)
{
    m_acc = vector3d(0, 981, 0);
    m_vel = vector3d(500, 0, 0);
    m_pos = vector3d(5, 5, 0);
    m_size = vector3d(250.0, 186.0, 0.0);
    m_window = window;
    if( !m_image_running.LoadFromFile("resource/sprites/run_cycle_sheet.png") )
        std::cout<< "error" << std::endl;
   else
        m_sprite_running.SetImage(m_image_running);
    m_frame = 0;
    m_last_frame_time = 0;
    m_frame_time = 0.03;

}

Character::~Character()
{
}

void Character::display()
{
    std::cout<< m_pos.x() << std::endl;
    m_sprite_running.SetX(m_pos.x());
    m_sprite_running.SetY(m_pos.y());
    m_sprite_running.SetSubRect(sf::IntRect(m_frame * 250, 0, m_frame*250+250, 186));
    m_window->Draw(m_sprite_running);
}

void Character::addAcc( double x, double y)
{
    if( onPlatform() )
    {
        m_acc.sx(m_acc.x() + x );
        m_acc.sy(m_acc.y() + y );
    }
}

void Character::update(double new_time)
{
    double step_time = new_time - m_last_time;
    m_vel.sx(m_vel.x() + m_acc.x() * step_time );
    m_vel.sy(m_vel.y() + m_acc.y() * step_time );
    if( m_vel.y() > 100 )
        m_vel.sy(600);
    m_pos.sx(m_pos.x() + m_vel.x() * step_time );
    m_pos.sy(m_pos.y() + m_vel.y() * step_time );
    m_offset = m_vel.x() * step_time;
    if(m_pos.y() > 414)
    {
        m_pos.sy(414);
        m_vel.sy(0);
    }
    for( int i = 0; i < ((Super*)thesuper)->numP(); i ++)
    {
        Platform platform = ((Super*)thesuper)->getP(i);
        int distance = collision(platform);
        if( collision(platform) != -1)
        {
            m_pos.sy(m_pos.y() - distance);
            m_vel.sy(0);
        }
    }
    m_acc.sx(0);
    m_acc.sy(981);
    m_last_frame_time += step_time;
    if( m_last_frame_time > m_frame_time )
    {
        m_last_frame_time = 0;
        m_frame--;
        if( m_frame < 0)
            m_frame = 13;
    }
    m_last_time = new_time;
}

void Character::sx( int x )
{
    m_pos.sx(x);
}

int Character::offset()
{
    return m_offset;
}

bool Character::onPlatform()
{
    return m_vel.y() == 0;
}

int Character::collision(Platform platform)
{
    if(  m_pos.x() + m_size.x() < platform.pos().x()
       || m_pos.y() + 186  < platform.pos().y()
       || m_pos.x() > platform.pos().x() + platform.size().x()
       || m_pos.y() + 166 > platform.pos().y() + platform.size().y()  )
    {
        // std::cout<<  m_pos.x() << "  " << m_pos.y() << "   " <<  m_size.x() << "   " <<  m_size.y() << "   " <<   platform.pos().x() << "  " <<  platform.pos().y() << "   " <<  platform.size().x() << "   " <<  platform.size().y() << std::endl;
        return -1;
    }
    else if ( m_vel.y() > -1 )
    {
        // std::cout<< "ERROR" <<  platform.pos().y() - m_pos.y() << std::endl;
        return ( m_pos.y() + m_size.y() ) - platform.pos().y();
    }
    else
    {
        return -1;
    }
}

