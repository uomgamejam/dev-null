#include "character.hpp"
#include "super.hpp"
#include "upgrade.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


Character::Character(void* superclass, sf::RenderWindow* window) : thesuper(superclass)
{
    m_acc = vector3d(0, 5000, 0);
    m_vel = vector3d(500, 0, 0);
    m_pos = vector3d(5, 5, 0);
    m_size = vector3d(200.0, 186.0, 0.0);
    m_window = window;
    if( !m_image_running.LoadFromFile("resource/sprites/run_cycle_sheet.png")
        || !m_image_upgrades[0].LoadFromFile("resource/sprites/bandanna_cycle_sheet.png")
        || !m_image_upgrades[1].LoadFromFile("resource/sprites/cape_cycle_sheet.png")
        || !m_image_upgrades[2].LoadFromFile("resource/sprites/shuriken_cycle_sheet.png"))
        std::cout<< "error" << std::endl;
   else
   {
        m_sprite_running.SetImage(m_image_running);
        m_sprite_upgrade[0].SetImage(m_image_upgrades[0]);
        m_sprite_upgrade[1].SetImage(m_image_upgrades[1]);
        m_sprite_upgrade[2].SetImage(m_image_upgrades[2]);
   }
    upgrade[0] = false;
    upgrade[1] = false;
    upgrade[2] = true;
    m_frame = 0;
    m_last_frame_time = 0;
    m_frame_time = 0.01;
    nbTokens = 0;
    scoreTime = 0;
    nbShurikan = 2;
}

Character::~Character()
{
}

void Character::display()
{
    m_sprite_running.SetX(m_pos.x());
    m_sprite_running.SetY(m_pos.y());
    m_sprite_running.SetSubRect(sf::IntRect(m_frame * 250, 0, m_frame*250+250, 186));
    m_sprite_running.SetScale(0.5,0.5);
    m_window->Draw(m_sprite_running);
    for( int i = 0; i < 3; i++ )
    {
        if(upgrade[i])
        {
            m_sprite_upgrade[i].SetX(m_pos.x());
            m_sprite_upgrade[i].SetY(m_pos.y());
            m_sprite_upgrade[i].SetSubRect(sf::IntRect(m_frame * 250, 0, m_frame*250+250, 186));
            m_sprite_upgrade[i].SetScale(0.5,0.5);
            m_window->Draw( m_sprite_upgrade[i]);
        }
    }
}

void Character::addVel( double x, double y)
{
    if( onPlatform() )
    {
        m_vel.sx(m_vel.x() + x );
        m_vel.sy(m_vel.y() + y );
    }
}

void Character::update(double new_time)
{
    double step_time = new_time - m_last_time;
    scoreTime += step_time;
    //m_vel.sx(m_vel.x() + m_acc.x() * step_time );
    //m_vel.sy(m_vel.y() + m_acc.y() * step_time );
    m_vel += m_acc * step_time;
    //if( m_vel.y() > 1000 )
    //    m_vel.sy(1000);
    //m_pos.sx(m_pos.x() + m_vel.x() * step_time );
    //m_pos.sy(m_pos.y() + m_vel.y() * step_time );
    m_pos += m_vel * step_time;
    m_offset = m_vel.x() * step_time;
    double offset_y = m_vel.y() * step_time;
    for( int i = 0; i < ((Super*)thesuper)->numP(); i ++)
    {
        Platform platform = ((Super*)thesuper)->getP(i);
        int distance = collision(platform, offset_y);
        if( distance != -1)
        {
            m_pos.sy(m_pos.y() - distance);
            m_vel.sy(0);
        }
    }
    if(m_pos.y() > 507)
    {
        m_pos.sy(507);
        m_vel.sy(0);
    }
    m_last_frame_time += step_time;
    if( m_last_frame_time > m_frame_time )
    {
        m_last_frame_time = 0;
        m_frame--;
        if( m_frame < 0)
            m_frame = 13;
    }
    m_last_time = new_time;
    for( int i = 0; i < ((Super*)thesuper)->numU(); i ++)
    {
        Upgrade upgrade_temp = ((Super*)thesuper)->getU(i);
        if( simpleCollision(upgrade_temp))
        {
            nbTokens++;
            if( upgrade_temp.getUpgradeFlags() == UT_CLOTHING)
            {
                upgrade[rand()%2] = true;
            }
            else if ( upgrade_temp.getUpgradeFlags() == UT_IDEA)
            {
                ((Super*)thesuper)->addBackground();
            }
            else if( upgrade_temp.getUpgradeFlags() == UT_WEAPON)
            {
                upgrade[2] = true;
                nbShurikan++;
            }
            ((Super*)thesuper)->deleteU(i);
        }
    }
    for( int i = 0; i < ((Super*)thesuper)->numW(); i ++)
    {
        Wall wall_temp = ((Super*)thesuper)->getW(i);
        if( simpleCollision(wall_temp))
        {
            ((Super*)thesuper)->stop = true;
            m_vel.sx(0);
        }
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

bool Character::onPlatform()
{
    return m_vel.y() == 0;
}

int Character::collision(Platform platform, double offsety)
{
    // std::cout<< offsety << std::endl;
    if(  m_pos.x() + m_size.x() / 2 - 25 < platform.pos().x()
       || m_pos.y() + 186 / 2 < platform.pos().y()
       || m_pos.x() + 38 > platform.pos().x() / 2 + platform.size().x()
       || m_pos.y() - offsety + ( 146 / 2 ) > platform.pos().y() + platform.size().y()  )
    {
       // std::cout<<  m_pos.x() << "  " << m_pos.y() << "   " <<  m_size.x() << "   " <<  m_size.y() << "   " <<   platform.pos().x() << "  " <<  platform.pos().y() << "   " <<  platform.size().x() << "   " <<  platform.size().y() << std::endl;
        return -1;
    }
    else if ( m_vel.y() > -1 )
    {
        // std::cout<< "ERROR" <<  platform.pos().y() - m_pos.y() << std::endl;
        return ( m_pos.y() + m_size.y() / 2 ) - platform.pos().y();
    }
    else
    {
        return -1;
    }
}

bool Character::simpleCollision(Upgrade upgrade)
{
        if(  m_pos.x() + m_size.x() / 2  < upgrade.pos().x()
       || m_pos.y() + m_size.y() / 2 < upgrade.pos().y()
       || m_pos.x()  > upgrade.pos().x() / 2 + upgrade.size().x()
       || m_pos.y()  > upgrade.pos().y() + upgrade.size().y()  )
       {
           return false;
       }
       else
       {
           return true;
       }
}

bool Character::simpleCollision(Wall wall)
{
        if(  m_pos.x() + m_size.x() / 2 - 35 < wall.pos().x()
       || m_pos.y() + m_size.y() / 2 < wall.pos().y()
       || m_pos.x() + 35 > wall.pos().x() / 2 + wall.size().x()
       || m_pos.y()  > wall.pos().y() + wall.size().y()  )
       {
           return false;
       }
       else
       {
           return true;
       }
}

bool Character::attaq()
{
    if( nbShurikan > 0 )
    {

      nbShurikan--;
      if ( nbShurikan == 0 )
        upgrade[2] = false;
      return true;
    }
    else
    {
        return false;
    }
}

