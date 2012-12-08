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
  for (i = 0; i < platforms.size(); i ++)
  {
    iter = std::next(platforms.begin(), i);
    iter->display();
  }
  player.display();
}

void Super::createPlatforms()
{
  if (platforms.back.x() + platforms.back().w() + 300 < 1200)
  {
    platform newPlatform();
    platforms.push_back(newPlatform);
  }
}

void Super::removePlatforms()
{
  for (i = 0; i < platforms.size(); i ++)
  {
    iter = std::next(platforms.begin(), i);
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
    iter = std::next(platforms.begin(), i);
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
