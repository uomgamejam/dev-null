
#include "platform.hpp"

Platform::Platform(sf::RenderWindow* thewindow)
{
	window = thewindow;
	
	if (!platformimage.LoadFromFile("./ressources/sprites/platform1.png"))
	{
		// Error...
	}
	else
	{
		platformsprite.SetImage(platformimage);
	}
	
	m_pos.reset();
	m_size.sxyz(100.0d, 100.0d, 0.0d);
	m_vel.reset();
}

Platform::Platform(double x, double y, double w, double h)
{
	m_pos.sxyz(x, y, 0.0d);
	m_size.sxyz(w, h, 0.0d);
}

Platform::~Platform()
{
	// Nothing to free
}

void Platform::update(double timestep)
{
	m_pos += m_vel * timestep;
}

void Platform::display()
{
	//TODO:
	platformsprite.resize(size.x(), size.y());
	window->display(platformsprite);
}

void Platform::setpos(double x, double y)
{
	m_pos.sxyz(x, y, 0.0d);
}

void Platform::setsize(double w, double h)
{
	m_size.sxyz(w, h, 0.0d);
}

const vector3d& Platform::pos()
{
	return m_pos; 
}

const vector3d& Platform::size()
{
	return m_size;
}
