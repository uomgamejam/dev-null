#include "super.hpp"
#include "platform.hpp"
#include "background.hpp"

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
  double time = clock.GetElapsedTime();
  movePlayer(time);
  moveAll(time);
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
  player.display();
}

void Super::createPlatforms()
{
  if (platforms.back()->pos().x() + platforms.back()->size().x() + 100 < 1200)
  {
    platforms.push_back(new Platform(m_window));
    platforms.back()->setpos((rand()%300)+1200, (rand()%200)+350);
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
    (*iter)->setpos((*iter)->pos().x() - (4 * speed), (*iter)->pos().y());
    iter ++;
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

void Super::addAcc( double x, double y)
{
    player.addAcc(x,y);
}
