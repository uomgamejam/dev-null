#include "super.hpp"
#include "platform.hpp"

Super::Super(sf::RenderWindow* window): player(this, window), clock()
{
    m_window = window;
    clock.Reset();
    platforms.push_back(new Platform(m_window));

}

Super::~Super()
{
	// Nothing to free
}

void Super::update()
{
  movePlayer();
  moveAll();
  createPlatforms();
  removePlatforms();
}

void Super::display()
{
  std::list<Platform*>::iterator iter = platforms.begin();
  for (i = 0; i < platforms.size(); i ++)
  {
        (*iter)->display();
        iter++;
  }
  player.display();
}

void Super::createPlatforms()
{
  if (platforms.back()->pos().x() + platforms.back()->size().y() + 300 < 1200)
  {
    platforms.push_back(new Platform(m_window));
    platforms.back()->setpos(100, 100);
  }
}

void Super::removePlatforms()
{
  std::list<Platform*>::iterator iter = platforms.begin();
  if (platforms.front()->pos().x() + platforms.front()->size().x() < 0)
    platforms.erase(iter);
}

void Super::movePlayer()
{
  player.update(clock.GetElapsedTime());
}

void Super::moveAll()
{
  std::list<Platform*>::iterator iter = platforms.begin();
  for (i = 0; i < platforms.size(); i ++)
  {
    (*iter)->setpos((*iter)->pos().x() - player.offset(), (*iter)->pos().y());
    iter ++;
  }

  player.sx(player.pos().x() - player.offset());
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
