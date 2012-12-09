
#include "vector3d.hpp"

#ifndef __UPGRADE__HPP__
#define __UPGRADE__HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


typedef enum UPGRADE_TYPE
{
    UT_HIGH_G = 0x1,
    UT_LOW_G = 0x2,
    UT_CLOTHING = 0x3,
    UT_IDEA = 0x4,
    UT_WEAPON = 0x5
    //PUT other pugrade flags here
};


class Upgrade{


public:
    Upgrade();
    Upgrade(double, double, sf::RenderWindow* window);
    ~Upgrade();

    void update(double offset);
    //
    const vector3d& pos();
    void setpos(const vector3d& newpos);
    //
    const vector3d& vel();
    void setvel(const vector3d newvel);
    //
    const vector3d& size();

    void setUpgradeFlags(UPGRADE_TYPE upgrade);
    UPGRADE_TYPE getUpgradeFlags();

    void display();



protected:



private:
    vector3d m_pos;
    vector3d m_size;
    vector3d m_vel;
    UPGRADE_TYPE m_upgrade_flags;
    sf::RenderWindow* m_window;
    sf::Image upgradeimage;
    sf::Sprite upgradesprite;



};



#endif // __UPGRADE__HPP__
