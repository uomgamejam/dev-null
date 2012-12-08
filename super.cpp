#include "super.hpp"

Super::Super()
{

}

void Super::update()
{
  movePlayer();
  moveAll();
  createPlatforms();
  removePlatforms();
  display();
}

void Super::display()
{  
  std::list<platform>::iterator iter;
  for (i = 0; i < platforms.size(); i ++)
  {
    iter ++;
    iter->display();
  }
  player.display();
}

void Super::createPlatforms()
{
  std::list<platform>::iterator iter;
  if (platforms.back.x() + platforms.back().w() + 300 < 1200)
  {
    platform newPlatform();
    platforms.push_back(newPlatform);
  }
}

void Super::removePlatforms()
{
  std::list<platform>::iterator iter;
  for (i = 0; i < platforms.size(); i ++)
  {
    iter ++;
    if (iter->x() + iter->.w() < 0)
      platforms.erase(i);
  }
}

void Super::movePlayer()
{
  player.update();
}

void Super::moveAll()
{
  std::list<platform>::iterator iter;
  for (i = 0; i < platforms.size(); i ++)
  {
    iter ++;
    iter->sx(iter->x() - player.vel().x());
  }

  player.sx(player.x() - player.vel().x());
}

int Super::numP()
{
  return platforms.size();
}

Platform Super::getP(int index)
{
  return platforms.at(index);
}
