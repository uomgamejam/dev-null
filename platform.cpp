
#include "platform.hpp"

Platform::Platform(sf::RenderWindow* thewindow)
{
	window = thewindow;

	if (!platformimage.LoadFromFile("resource/sprites/platform1.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		platformsprite.SetImage(platformimage);
	}

	m_pos.reset();
	m_size.sxyz(200.0, 31, 0.0);
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
    platformsprite.SetX(m_pos.x());
    platformsprite.SetY(m_pos.y());
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
