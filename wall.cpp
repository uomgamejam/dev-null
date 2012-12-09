#include "wall.hpp"

Wall::Wall(sf::RenderWindow* thewindow)
{
	window = thewindow;

	if (!wallimage.LoadFromFile("resource/sprites/mental_block.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		wallsprite.SetImage(wallimage);
	}

	m_pos.reset();
	m_size.sxyz(31, 200, 0);
}

Wall::Wall(double x, double y, double w, double h)
{
	m_pos.sxyz(x, y, 0.0);
	m_size.sxyz(w, h, 0.0);
}

Wall::~Wall()
{
	// Nothing to free
}

void Wall::update(double offset)
{
	//TODO:
}

void Wall::display()
{
    wallsprite.SetX(m_pos.x());
    wallsprite.SetY(m_pos.y());
	window->Draw(wallsprite);
}

void Wall::setpos(double x, double y)
{
	m_pos.sxyz(x, y, 0.0);
}

void Wall::setsize(double w, double h)
{
	m_size.sxyz(w, h, 0.0);
}

const vector3d& Wall::pos()
{
	return m_pos;
}

const vector3d& Wall::size()
{
	return m_size;
}

