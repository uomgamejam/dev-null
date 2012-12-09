#include "super.hpp"
#include "platform.hpp"
#include "background.hpp"
#include <vector>

Super::Super(sf::RenderWindow* window): player(this, window), background(window), clock()
{
    m_window = window;
    clock.Reset();
    lastTime = clock.GetElapsedTime();
    platforms.push_back(new Platform(m_window));
    platforms.back()->setpos(1200, 400);
    background.setpos(0,0);
}
Super::~Super()
{
	// Nothing to free
}

void Super::update()
{
  double newTime = clock.GetElapsedTime();
  movePlayer(newTime);
  moveAll(newTime);
  createPlatforms();
  removePlatforms();
}

void Super::display()
{
  std::list<Platform*>::iterator iter = platforms.begin();
  background.display();
  for (i = 0; i < platforms.size(); i ++)
  {
        (*iter)->display();
        iter++;
  }
   for( int j = 0; j < upgrades.size(); j++)
  {
      upgrades[j]->display();
  }
  player.display();
}

void Super::createPlatforms()
{
  if (platforms.back()->pos().x() + platforms.back()->size().x() + 100 < 1200)
  {
        platforms.push_back(new Platform(m_window));
        int posX = rand()%300+1200;
        int posY =  rand()%200+350;
        platforms.back()->setpos(posX, posY);
        if( rand()%5 == 0 )
        {
            upgrades.push_back(new Upgrade(posX+125, posY-50, m_window));
        }
  }
}

void Super::removePlatforms()
{
  std::list<Platform*>::iterator iter = platforms.begin();
  if (platforms.front()->pos().x() + platforms.front()->size().x() < 0)
    platforms.erase(iter);
}

void Super::movePlayer(double time)
{
  player.update(time);
}

void Super::moveAll(double time)
{
  double speed = 70 * (time - lastTime);
  std::list<Platform*>::iterator iter = platforms.begin();
  background.update(speed);
  for (i = 0; i < platforms.size(); i ++)
  {
    (*iter)->setpos((*iter)->pos().x() - player.offset(), (*iter)->pos().y());
    iter ++;
  }
  for( int j = 0; j < upgrades.size(); j++)
  {
      upgrades[j]->update(player.offset());
  }
  player.sx(player.pos().x() - player.offset());

  lastTime = time;
}

int Super::numP()
{
  return platforms.size();
}

Platform Super::getP(int index)
{
  std::list<Platform*>::iterator iter = platforms.begin();
  for( int i = 0; i < index; i++)
    iter++;
  return *(*iter);
}

int Super::numU()
{
  return upgrades.size();
}

Upgrade Super::getU(int index)
{
  return *(upgrades[index]);
}

void Super::deleteU(int index)
{
    for(int i = index; i < upgrades.size()- 1; i++)
    {
        upgrades[i] = upgrades[i+1];
    }
    upgrades.pop_back();
}

void Super::addVel( double x, double y)
{
    player.addVel(x,y);
}
