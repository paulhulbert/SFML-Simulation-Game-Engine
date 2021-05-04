#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Query.h"
using namespace sf;
class GameUI
{
public:
	GameUI(RenderWindow* app);
	GameObject* selectedObject;
	void render();
	Sprite* backgroundSprite;
	void mouseClicked();
	Person* player;
private:
	RenderWindow* app;
	Font* font;
	Query* currentQuery;
	void renderQueries();
};

