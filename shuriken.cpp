#include "shuriken.hpp"
#include "super.hpp"

Shuriken::Shuriken(void* superclass, sf::RenderWindow* thewindow): thesuper(superclass)
{
	window = thewindow;

	if (!shurikenimage.LoadFromFile("resource/sprites/weapon_assets/shuriken.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		shurikensprite.SetImage(shurikenimage);
	}

	m_pos.reset();
	m_size.sxyz(30, 30, 0);
	m_vel.sxyz(750, 0,0);
	first = true;
}


Shuriken::~Shuriken()
{
	// Nothing to free
}

void Shuriken::update(double time)
{
    double step_time = 0;
    if( !first)
    {
        step_time = time - lastTime;
        m_pos += m_vel * step_time;
    }
	lastTime = time;
	first = false;


    for( int i = 0; i < ((Super*)thesuper)->numW(); i ++)
    {
        Wall wall_temp = ((Super*)thesuper)->getW(i);
        if( simpleCollision(wall_temp, m_vel.x() * step_time))
        {
            ((Super*)thesuper)->deleteW(i);
            ((Super*)thesuper)->deleteS(0);
        }
    }
}

void Shuriken::display()
{
    shurikensprite.SetX(m_pos.x());
    shurikensprite.SetY(m_pos.y());
	window->Draw(shurikensprite);
}

void Shuriken::setpos(double x, double y)
{
	m_pos.sxyz(x, y, 0.0);
}

void Shuriken::setsize(double w, double h)
{
	m_size.sxyz(w, h, 0.0);
}

const vector3d& Shuriken::pos()
{
	return m_pos;
}

const vector3d& Shuriken::size()
{
	return m_size;
}

bool Shuriken::simpleCollision(Wall wall, double offsetx)
{
        if(  m_pos.x() + m_size.x()   < wall.pos().x()
       || m_pos.y() + m_size.y()  < wall.pos().y()
       || m_pos.x() - offsetx > wall.pos().x() + wall.size().x()
       || m_pos.y()  > wall.pos().y() + wall.size().y()  )
       {
           return false;
       }
       else
       {
           return true;
       }
}
