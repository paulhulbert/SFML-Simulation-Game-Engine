#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h";
#include "DataLoader.h"
#include "GameEngine.h"
#include "Constants.h"

using namespace sf;
using std::endl;
using std::cout;


int main()
{
    RenderWindow app(VideoMode(1920, 1080), "Simulation Engine");
    DataLoader::initialize();
    app.setFramerateLimit(60);

    GameEngine gameEngine(&app);

    Font font;
    font.loadFromFile("images/arial.ttf");

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                app.close();
            }
            else if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
            {
                gameEngine.mouseClicked();
            }
        }

        app.clear(Color::Color(100, 100, 100));

        gameEngine.tick(1);

        
        app.display();
    }

    return 0;
}