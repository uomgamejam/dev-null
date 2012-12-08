#include "super.hpp"
#include "platform.hpp"

Super::Super(sf::RenderWindow* window): player(this, window), clock()
{
    m_window = window;
    clock.Reset();
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
  display();
}

void Super::display()
{
  std::list<Platform>::iterator iter = platforms.begin();
  for (i = 0; i < platforms.size(); i ++)
  {
    iter->display();
    iter++;
  }
  player.display();
}

void Super::createPlatforms()
{
  std::list<Platform>::iterator iter = platforms.begin();
  if (platforms.back().pos().x() + platforms.back().size().x() + 300 < 2400)
  {
    Platform newPlatform = Platform(m_window);
    platforms.push_back(newPlatform);
  }
}

void Super::removePlatforms()
{
  std::list<Platform>::iterator iter = platforms.begin();
  for (i = 0; i < platforms.size() - 1; i ++)
  {
      std::cout << i << std::endl;
      std::cout << platforms.size() << std::endl;

    if (iter->pos().x() + iter->size().x() < 0)
      platforms.erase(iter);
    iter ++;
  }
}

void Super::movePlayer()
{
  player.update(clock.GetElapsedTime());
}

void Super::moveAll()
{
  std::list<Platform>::iterator iter = platforms.begin();
  for (i = 0; i < platforms.size(); i ++)
  {
    iter ++;
    iter->setpos(iter->pos().x() - player.offset(), iter->pos().y());
  }

  player.sx(player.pos().x() - player.offset());
}

int Super::numP()
{
  return platforms.size();
}

Platform Super::getP(int index)
{
  std::list<Platform>::iterator iter = platforms.begin();
  for( int i = 0; i < index; i++)
    iter++;
  return *iter;
}
