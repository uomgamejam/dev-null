
#include "platform"

platform::platform()
{
	m_pos.reset();
	m_size.sxyz(100.0d, 100.0d, 0.0d);
	m_vel.reset();
}

platform::platform(double x, double y, double w, double h, double vx, double vy);
{
	m_pos.sxyz(x, y, 0.0d);
	m_size.sxyz(w, h, 0.0d);
	m_vel.sxyz(vx, vy, 0.0d);
}

platform::~platform()
{
	// Nothing to free
}

void platform::update(double timestep)
{
	m_pos += m_vel * timestep;
}

void platform::draw()
{
	//TODO:
}

void setpos(double x, double y)
{
	m_pos.sxyz(x, y, 0.0d);
}

void setsize(double w, double h)
{
	m_size.sxyz(w, h, 0.0d);
}

void setvel(double vx, double vy)
{
	m_vel.sxyz(vx, vy, 0.0d);
}
