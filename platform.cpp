
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
	m_size.sxyz(100.0, 100.0, 0.0);
}

Platform::Platform(double x, double y, double w, double h)
{
	m_pos.sxyz(x, y, 0.0);
	m_size.sxyz(w, h, 0.0);
}

Platform::~Platform()
{
	// Nothing to free
}

void Platform::update(double timestep)
{
	//TODO:
}

void Platform::display()
{
	//TODO:
	platformsprite.Resize(m_size.x(), m_size.y());
	window->Draw(platformsprite);
}

void Platform::setpos(double x, double y)
{
	m_pos.sxyz(x, y, 0.0);
}

void Platform::setsize(double w, double h)
{
	m_size.sxyz(w, h, 0.0);
}

const vector3d& Platform::pos()
{
	return m_pos;
}

const vector3d& Platform::size()
{
	return m_size;
}
