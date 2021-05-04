#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameUI.h"
#include "DataLoader.h"
#include "GameObjects/Person.h"
#include "AIs/PlayerCharacterAI.h"
using namespace sf;
using std::cout;
using std::endl;

GameUI::GameUI(RenderWindow* app)
{
	this->app = app;
    selectedObject = NULL;
	backgroundSprite = new Sprite(*DataLoader::uITexture);
	backgroundSprite->setScale(70, 5);
	backgroundSprite->setPosition(0, 1200);
    font = new Font();;
    font->loadFromFile("images/arial.ttf");
    player = NULL;
    currentQuery = NULL;
}

void GameUI::render()
{
    View gameView = app->getView();
    app->setView(app->getDefaultView());
    app->draw(*backgroundSprite);

    RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(150, 150));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setOrigin(75, 75);
    rectangle.setPosition(150, 1300);
    app->draw(rectangle);

    rectangle.setSize(sf::Vector2f(300, 150));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setOrigin(150, 75);
    rectangle.setPosition(800, 1300);
    app->draw(rectangle);

    rectangle.setSize(sf::Vector2f(500, 100));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setOrigin(250, 50);
    rectangle.setPosition(1500, 1275);
    app->draw(rectangle);


    if (!((PlayerCharacterAI*)player->AIs.at(0))->activeQueries.empty())
    {
        currentQuery = ((PlayerCharacterAI*)player->AIs.at(0))->activeQueries.front();
    }
    if (currentQuery != NULL && currentQuery->response == -1)
    {
        renderQueries();
    }



    rectangle.setSize(sf::Vector2f(30, 30));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(Color::Red);
    rectangle.setOutlineThickness(5);
    rectangle.setOrigin(15, 15);
    rectangle.setPosition(2300, 1300);
    app->draw(rectangle);


    if (selectedObject != NULL)
    {
        selectedObject->getSprite()->setPosition(150, 1300);
        selectedObject->getSprite()->setRotation(0);
        Vector2f currentScale = selectedObject->getSprite()->getScale();
        selectedObject->getSprite()->setScale((50 * currentScale.x / currentScale.y) / selectedObject->getSprite()->getTexture()->getSize().x, (50 * currentScale.y / currentScale.x) / selectedObject->getSprite()->getTexture()->getSize().y);
        app->draw(*selectedObject->getSprite());
        selectedObject->getSprite()->setScale(currentScale);

        Text nameText;
        nameText.setPosition(100, 1225);
        nameText.setFont(*font);
        nameText.setString(selectedObject->name);
        nameText.setCharacterSize(18);
        nameText.setFillColor(Color::Black);
        nameText.setStyle(Text::Bold | sf::Text::Underlined);
        app->draw(nameText);


        Text statusText;
        statusText.setPosition(680, 1225);
        statusText.setFont(*font);
        statusText.setString(selectedObject->getStatusPanelString());
        statusText.setCharacterSize(14);
        statusText.setFillColor(Color::Black);
        statusText.setStyle(Text::Bold);
        app->draw(statusText);
    }


    Vector2i position = Mouse::getPosition(*app);
    auto translated_pos = app->mapPixelToCoords(position);
    if (!backgroundSprite->getGlobalBounds().contains(translated_pos))
    {
        translated_pos = app->mapPixelToCoords(position, gameView);
    }
    Text text;
    text.setPosition(350, 1300);
    text.setFont(*font);
    text.setString(to_string((int)translated_pos.x) + ", " + to_string((int)translated_pos.y));
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold | sf::Text::Underlined);
    app->draw(text);

    app->setView(gameView);
}

void GameUI::mouseClicked()
{
    auto mouse_pos = sf::Mouse::getPosition(*app);
    auto translated_pos = app->mapPixelToCoords(mouse_pos, app->getDefaultView());

    if (translated_pos.x > 2300 - 15 && translated_pos.x < 2300 + 15 && translated_pos.y > 1300 - 15 && translated_pos.y < 1300 + 15)
    {
        exit(0);
    }

    if (currentQuery != NULL && currentQuery->response == -1)
    {
        if (translated_pos.y > 1375 - 25 && translated_pos.y < 1375 + 25)
        {
            for (int i = 0; i < currentQuery->options.size(); i++)
            {
                if (translated_pos.x > 1325 - 75 && translated_pos.x < 1325 + i * 160 + 75)
                {
                    currentQuery->response = i;
                    break;
                }
            }
        }
    }

}

void GameUI::renderQueries()
{
    for (int i = 0; i < currentQuery->options.size(); i++)
    {
        RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(150, 50));
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setFillColor(Color::White);
        rectangle.setOutlineThickness(5);
        rectangle.setOrigin(75, 25);
        rectangle.setPosition(1325 + i * 160, 1375);
        app->draw(rectangle);

        Text text;
        text.setOrigin(75, 25);
        text.setPosition(1325 + i * 160, 1375);
        text.setFont(*font);
        text.setString(currentQuery->options.at(i));
        text.setCharacterSize(14);
        text.setFillColor(Color::Black);
        text.setStyle(Text::Bold);
        app->draw(text);
    }
}
