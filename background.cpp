#include "background.hpp"

Background::Background(sf::RenderWindow* thewindow)
{
	window = thewindow;

	if (!backgroundimage[0].LoadFromFile("resource/sprites/background_assets/background_sky.png")
	    || !backgroundimage[1].LoadFromFile("resource/sprites/background_assets/background_mountains_back.png")
	    || !backgroundimage[2].LoadFromFile("resource/sprites/background_assets/background_cloudlayer_middle.png")
	    || !backgroundimage[3].LoadFromFile("resource/sprites/background_assets/background_mountains_middle.png")
	    || !backgroundimage[4].LoadFromFile("resource/sprites/background_assets/background_cloudlayer_fore.png")
	    || !backgroundimage[5].LoadFromFile("resource/sprites/background_assets/background_mountains_fore.png")
	    || !backgroundimage[6].LoadFromFile("resource/sprites/background_assets/background_cloud1_top.png")
	    || !backgroundimage[7].LoadFromFile("resource/sprites/background_assets/background_cloud2_top.png")
	    || !backgroundimage[8].LoadFromFile("resource/sprites/background_assets/background_cloud3_top.png")
	    || !backgroundimage[9].LoadFromFile("resource/sprites/background_assets/background_grass_bottom.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
	  for (i = 0; i < 10; i ++)
	  {
	    backgroundsprite[i].SetImage(backgroundimage[i]);
	    backgroundsprite[i+10].SetImage(backgroundimage[i]);
	  }
	}	

	m_pos.reset();
}

Background::Background(double x, double y)
{
	m_pos.sxyz(x, y, 0.0);
}

Background::~Background()
{
	// Nothing to free
}

void Background::update(double speed)
{
	m_pos.sx(m_pos.x() - speed);
	if (m_pos.x() + 1200 < 0)
	  m_pos.sx(0);
	
	for (i = 0; i < 10; i ++)
          backgroundsprite[i].SetPosition(m_pos.x(), m_pos.y());
        for (i = 10; i < 20; i ++)
          backgroundsprite[i].SetPosition(m_pos.x() + 1200, m_pos.y());	  
}

void Background::display()
{
	for (i = 0; i < 20; i ++)
	  window->Draw(backgroundsprite[i]);
}

void Background::setpos(double xIn, double yIn)
{
	m_pos.sxyz(xIn, yIn, 0.0);
}
