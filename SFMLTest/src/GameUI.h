#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace sf;
class GameUI
{
public:
	GameUI(RenderWindow* app);
	GameObject* selectedObject;
	void render();
	Sprite* backgroundSprite;
private:
	RenderWindow* app;
	Font* font;
};

