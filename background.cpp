#include "background.hpp"

Background::Background(sf::RenderWindow* thewindow)
{
	window = thewindow;
	maxLayer = 1;

	if (!backgroundimage[0].LoadFromFile("resource/sprites/background_assets/background_sky.png")
	    || !backgroundimage[1].LoadFromFile("resource/sprites/background_assets/background_mountains_back.png")
	    || !backgroundimage[2].LoadFromFile("resource/sprites/background_assets/background_cloudlayer_middle.png")
	    || !backgroundimage[3].LoadFromFile("resource/sprites/background_assets/background_mountains_middle.png")
	    || !backgroundimage[4].LoadFromFile("resource/sprites/background_assets/background_cloudlayer_fore.png")
        || !backgroundimage[5].LoadFromFile("resource/sprites/background_assets/background_cloudlayer_fore.png")
	    || !backgroundimage[6].LoadFromFile("resource/sprites/background_assets/background_mountains_fore.png")
	    || !backgroundimage[7].LoadFromFile("resource/sprites/background_assets/background_cloud1_top.png")
	    || !backgroundimage[8].LoadFromFile("resource/sprites/background_assets/background_cloud2_top.png")
	    || !backgroundimage[9].LoadFromFile("resource/sprites/background_assets/background_cloud3_top.png")
	    || !backgroundimage[10].LoadFromFile("resource/sprites/background_assets/background_grass_bottom.png"))
	{
		// Error...
		std::cout<< " error" << std::endl;
	}
	else
	{
	  for (i = 0; i < 11; i ++)
	  {
	    backgroundsprite[i].SetImage(backgroundimage[i]);
	    backgroundsprite[i+11].SetImage(backgroundimage[i]);
	  }
	}
    for (i = 0; i < 11; i ++)
        m_pos[i].reset();
}

Background::Background(double x, double y)
{
    for (i = 0; i < maxLayer; i ++)
        m_pos[i].sxyz(x, y, 0.0);
}

Background::~Background()
{
	// Nothing to free
}

void Background::update(double speed)
{
    for(i = 0; i < maxLayer; i++)
    {
        m_pos[i].sx(m_pos[i].x() - i * speed * 0.5);
        if (m_pos[i].x() + 1200 < 0)
          m_pos[i].sx(0);
        if( m_pos[i].y() > 0 )
           m_pos[i].sy(m_pos[i].y() - 2 * speed * 0.5);
    }

    m_pos[10].sx(m_pos[10].x() - 5 * speed * 0.5);
    if ( m_pos[10].x() + 1200 < 0)
      m_pos[10].sx(0);

	for (i = 0; i < maxLayer; i ++)
          backgroundsprite[i].SetPosition(m_pos[i].x(), m_pos[i].y());
    for (i = 11; i < maxLayer+11; i ++)
          backgroundsprite[i].SetPosition(m_pos[i-11].x() + 1200, m_pos[i-11].y());
     backgroundsprite[10].SetPosition(m_pos[10].x(), m_pos[10].y());
     backgroundsprite[21].SetPosition(m_pos[10].x() + 1200, m_pos[10].y());
}

void Background::display()
{
	for (i = 0; i < maxLayer; i ++)
	{
	    if( i!= 4 )
	    {
            window->Draw(backgroundsprite[i]);
            window->Draw(backgroundsprite[i+11]);
	    }
	}
	 window->Draw(backgroundsprite[10]);
     window->Draw(backgroundsprite[21]);
}

void Background::setpos(double xIn, double yIn)
{
    for (i = 0; i < 11; i ++)
        m_pos[i].sxyz(xIn, yIn, 0.0);
}

void Background::addLayer()
{
    if(maxLayer < 10 )
    {
        maxLayer += 1;
        m_pos[maxLayer-1].sy(600);
        if( maxLayer == 4)
        {
            maxLayer += 1;
            m_pos[maxLayer-1].sy(600);
        }
    }
}
