#include <SFML/Graphics.hpp>
#include "GameUI.h"
#include "DataLoader.h"
using namespace sf;

GameUI::GameUI(RenderWindow* app)
{
	this->app = app;
    selectedObject = NULL;
	backgroundSprite = new Sprite(*DataLoader::uITexture);
	backgroundSprite->setScale(50, 5);
	backgroundSprite->setPosition(0, 850);
    font = new Font();;
    font->loadFromFile("images/arial.ttf");
}

void GameUI::render()
{
    app->draw(*backgroundSprite);

    RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(150, 150));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setOrigin(75, 75);
    rectangle.setPosition(150, 950);
    app->draw(rectangle);


    if (selectedObject != NULL)
    {
        selectedObject->getSprite()->setPosition(150, 950);
        selectedObject->getSprite()->setRotation(0);
        Vector2f currentScale = selectedObject->getSprite()->getScale();
        selectedObject->getSprite()->setScale((50 * currentScale.x / currentScale.y) / selectedObject->getSprite()->getTexture()->getSize().x, (50 * currentScale.y / currentScale.x) / selectedObject->getSprite()->getTexture()->getSize().y);
        app->draw(*selectedObject->getSprite());
        selectedObject->getSprite()->setScale(currentScale);

        Text nameText;
        nameText.setPosition(100, 875);
        nameText.setFont(*font);
        nameText.setString(selectedObject->name);
        nameText.setCharacterSize(18);
        nameText.setFillColor(Color::Black);
        nameText.setStyle(Text::Bold | sf::Text::Underlined);
        app->draw(nameText);
    }


    Vector2i position = Mouse::getPosition(*app);
    Text text;
    text.setPosition(350, 950);
    text.setFont(*font);
    text.setString(to_string(position.x) + ", " + to_string(position.y));
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold | sf::Text::Underlined);
    app->draw(text);
}
