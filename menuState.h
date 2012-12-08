#ifndef DEF_MENUSTATE
#define DEF_MENUSTATE

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "state.h"
#include "quadNode.h"

class MenuState: public State
{
    public:
    MenuState(sf::RenderWindow* windowT, EventManager* eventManagerT);
    ~MenuState();
    void update();
    void render();

    private:
    QuadNode* quadNode;
    sf::Font menuFont;
    sf::String textPlay;
    sf::String textLoad;
    sf::String textExit;
    sf::RenderWindow* window;
};

#endif


