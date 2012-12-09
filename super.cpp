#include "super.hpp"
#include "platform.hpp"
#include "background.hpp"
#include <vector>
#include <SFML/Audio.hpp>

/*
void printText(int x, int y, std::string content, int size, sf::RenderWindow* window, Super* super){

	sf::String text(content, super->textFont, size);

	text.SetColor(sf::Color(0, 255, 0));
	text.SetRotation(90.0f);
	text.SetScale(2.0f, 2.0f);
	text.Move(x, y);

	window->Draw(text);

    if(!textFont.LoadFromFile("resource/font/ubuntu-font-family-0.80/UbuntuMono-R.ttf")){
    std::cout << "font load error!";
	}
}
*/

Super::Super(sf::RenderWindow* window): player(this, window), background(window), clock()
{
    m_window = window;
    clock.Reset();
    lastTime = clock.GetElapsedTime();
    platforms.push_back(new Platform(m_window));
    platforms.back()->setpos(1200, 400);
    background.setpos(0,0);
    distance_wall = 1000;
    distance_last_wall = 0;
    stop = false;
    if(!textFont.LoadFromFile("resource/font/ubuntu-font-family-0.80/UbuntuMono-R.ttf")){
		std::cout << "font load error!";
	}
}

Super::~Super()
{
	// Nothing to free
	std::list<Platform*>::iterator iter = platforms.begin();
    for (int i = 0; i < platforms.size(); i ++)
    {
        delete(*iter);
        iter ++;
    }
    for( int j = 0; j < upgrades.size(); j++)
    {
        delete(upgrades[j]);
    }
    for( int j = 0; j < walls.size(); j++)
    {
        delete(walls[j]);
    }
    for( int j = 0; j < shurikens.size(); j++)
    {
        delete(shurikens[j]);
    }
}

void Super::createWall()
{
    while( walls.size() < 4 )
    {
        walls.push_back(new Wall(m_window));
        walls[walls.size()-1]->setpos(distance_last_wall + distance_wall, 400);
        distance_last_wall += distance_wall;
    }
}

void Super::deleteWall()
{
    for( int j = 0; j < walls.size(); j++)
    {
        std::cout<<"deleteWall"<<std::endl;
        if( walls[j]->pos().x() + walls[j]->size().x() < 0)
        {
            std::cout<<"deleteWall"<<std::endl;
            deleteW(j);
        }
    }
}

void Super::attaq()
{
    if ( player.attaq())
    {
        shurikens.push_back(new Shuriken(this, m_window));
        shurikens[shurikens.size()-1]->setpos(player.pos().x(),player.pos().y());
    }
}

void Super::update()
{
  double newTime = clock.GetElapsedTime();
  movePlayer(newTime);
  moveAll(newTime);
  createPlatforms();
  removePlatforms();
  deleteWall();
  createWall();
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
    for( int j = 0; j < walls.size(); j++)
  {
      walls[j]->display();
  }
    for( int j = 0; j < shurikens.size(); j++)
  {
      shurikens[j]->display();
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
  for( int j = 0; j < walls.size(); j++)
  {
      walls[j]->setpos(walls[j]->pos().x() - player.offset(), walls[j]->pos().y());
  }
  for( int j = 0; j < shurikens.size(); j++)
  {
      shurikens[j]->update(time);
      shurikens[j]->setpos(shurikens[j]->pos().x() - player.offset(), shurikens[j]->pos().y());
  }
  player.sx(player.pos().x() - player.offset());

  lastTime = time;
}

int Super::numP()
{
  return platforms.size();
}

int Super::numW()
{
  return walls.size();
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

void Super::addBackground()
{
    background.addLayer();
}

Wall Super::getW(int index)
{
  return *(walls[index]);
}

void Super::deleteW(int index)
{
    for(int i = index; i < walls.size()- 1; i++)
    {
        walls[i] = walls[i+1];
    }
    walls.pop_back();
}

void Super::deleteS(int index)
{
    for(int i = index; i < shurikens.size()- 1; i++)
    {
        shurikens[i] = shurikens[i+1];
    }
    shurikens.pop_back();
}
