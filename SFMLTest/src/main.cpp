#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h";
#include "DataLoader.h"
#include "GameEngine.h"
#include "Constants.h"

using namespace sf;
using std::endl;
using std::cout;


void drawGridMesh(RenderWindow* app)
{
    for (int i = 0; i < 100; i++)
    {
        VertexArray lines(sf::LinesStrip, 0);

        lines.append(sf::Vector2f(i * Constants::TILE_LENGTH - .5 * Constants::TILE_LENGTH, 0));
        lines.append(sf::Vector2f(i * Constants::TILE_LENGTH - .5 * Constants::TILE_LENGTH, 2000));

        app->draw(lines);

        VertexArray lines2(sf::LinesStrip, 0);

        lines2.append(sf::Vector2f(0, i * Constants::TILE_LENGTH - .5 * Constants::TILE_LENGTH));
        lines2.append(sf::Vector2f(4000, i * Constants::TILE_LENGTH - .5 * Constants::TILE_LENGTH));

        app->draw(lines2);
    }
}


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

        drawGridMesh(&app);

        Vector2i position = Mouse::getPosition(app);

        Text text;
        text.setPosition(50, 950);
        text.setFont(font); 
        text.setString(to_string(position.x) + ", " + to_string(position.y));
        text.setCharacterSize(24); 
        text.setFillColor(Color::White);
        text.setStyle(Text::Bold | sf::Text::Underlined);
        app.draw(text);
        
        app.display();
    }

    return 0;
}