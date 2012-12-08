#include "super.hpp"

super::super()
{
	
}

void super::update()
{
  movePlayer();
  moveAll();
  createPlatforms();
  removePlatforms();
  display();
}

void super::display()
{
  for (i = 0; i < platforms.size(); i ++)
    platforms.at(i).display();
  player.display();
}

void super::createPlatforms()
{
  if (platforms.back.gx() + platforms.back.gl() + 300 < 1200)
  {
    platform newPlatform = new platform();
    platforms.push_back(newPlatform);
  }
}

void super::removePlatforms()
{
  for (i = 0; i < platforms.size(); i ++)
  {
    if (platforms.at(i).x() + platforms.at(i).w() < 0)
      platforms.erase(i);
  }
}

void super::movePlayer()
{
  player.update();
}

void super::moveAll()
{
  for (i = 0; i < platforms.size(); i ++)
    platforms.at(i).sx(platforms.at(i).x() - player.vel().x();
    
  player.sx(player.x() - player.vel().x());
}
