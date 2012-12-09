
#include "vector3d.hpp"

#ifndef __UPGRADE__HPP__
#define __UPGRADE__HPP__


enum UPGRADE_TYPE
{
    UT_HIGH_G = 0x1,
    UT_LOW_G = 0x2,
    //PUT other pugrade flags here
};


class Upgrade{


public:
    Upgrade();
    Upgrade(double, double);
    ~Upgrade();

    void update();
    //
    const vector3d& pos();
    void setpos(const vector3d& newpos);
    //
    const vector3d& vel();
    void setvel(const vector3d newvel);
    //
    void setUpgradeFlags(UPGRADE_TYPE upgrade);
    unsigned long getUpgradeFlags();



protected:



private:
    vector3d m_pos;
    vector3d m_vel;
    unsigned long m_upgrade_flags;


};



#endif // __UPGRADE__HPP__
