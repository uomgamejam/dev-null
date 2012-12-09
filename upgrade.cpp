#include "upgrade.hpp"


Upgrade::Upgrade()
{
    m_pos.reset();
    m_vel.reset();
    m_upgrade_flags = 0;
}

Upgrade::Upgrade(double x, double y)
{
    m_pos.sxyz(x, y, 0.0);
    m_vel.reset();
    m_upgrade_flags = 0;
}

Upgrade::~Upgrade()
{
    // Nothing to free
}

void Upgrade::update()
{
    m_pos += m_vel;
    //todo
    /*
    if(off the screen){
        delete self; (use the vector and remove)
    }
    */
}

const vector3d& const Upgrade::pos()
{
    return m_pos;
}

void Upgrade::setpos(const vector3d& newpos)
{
    m_pos.sxyz(newpos.x(), newpos.y(), 0.0);
}

const vector3d& const Upgrade::vel()
{
    return m_vel;
}

void Upgrade::setvel(const vector3d newvel)
{
    m_vel.sxyz(newvel.x(), newvel.y(), 0.0);
}

unsigned uint64_t Upgrade::setUpgradeFlags(UPGRADE_TYPES upgrade)
{
    m_upgrade_flags = 0;
    m_upgrade_flags = 0x1 << upgrade;
}

void Upgrade::getUpgradeFlags()
{
    return m_upgrade_flags;
}
