#include "upgrade.hpp"
#include <String>


Upgrade::Upgrade()
{
    m_pos.reset();
    m_vel.reset();
    m_upgrade_flags = UT_CLOTHING;
}

Upgrade::Upgrade(double x, double y, sf::RenderWindow* window)
{
    std::string file;
    switch(rand()%3)
    {
        case 0:
            file = "resource/sprites/collectibles/apparel-collectible-sheet.png";
            m_upgrade_flags = UT_CLOTHING;
        break;

        case 1:
            file = "resource/sprites/collectibles/idea-collectible-sheet.png";
            m_upgrade_flags = UT_IDEA;
        break;

        case 2:
            file = "resource/sprites/collectibles/weapon-collectible-sheet.png";
            m_upgrade_flags =UT_WEAPON;
        break;
    }
    if (!upgradeimage.LoadFromFile(file.c_str()))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
		upgradesprite.SetImage(upgradeimage);
	}
	m_size.sxyz( 50, 50, 0 );
    m_pos.sxyz(x, y, 0.0);
    m_vel.reset();
    m_window = window;
}

Upgrade::~Upgrade()
{
    // Nothing to free
}

void Upgrade::display()
{
    upgradesprite.SetX(m_pos.x());
    upgradesprite.SetY(m_pos.y());
    upgradesprite.SetSubRect(sf::IntRect( 0, 0, 50, 50));
	m_window->Draw(upgradesprite);
}

void Upgrade::update(double offset)
{
    m_pos.sx( m_pos.x() - offset );
    //todo
    /*
    if(off the screen){
        delete self; (use the vector and remove)
    }
    */
}

const vector3d& Upgrade::pos()
{
    return m_pos;
}

const vector3d& Upgrade::size()
{
    return m_size;
}

void Upgrade::setpos(const vector3d& newpos)
{
    m_pos.sxyz(newpos.x(), newpos.y(), 0.0);
}

const vector3d& Upgrade::vel()
{
    return m_vel;
}

void Upgrade::setvel(const vector3d newvel)
{
    m_vel.sxyz(newvel.x(), newvel.y(), 0.0);
}

void Upgrade::setUpgradeFlags(UPGRADE_TYPE upgrade)
{
    m_upgrade_flags = upgrade;
}

UPGRADE_TYPE Upgrade::getUpgradeFlags()
{
    return m_upgrade_flags;
}


