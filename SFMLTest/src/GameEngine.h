#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "GameObject.h"
#include "GameObjects/Room.h"
#include "GameUI.h"
using namespace sf;
using namespace std;
class GameEngine
{
public:
	GameEngine(RenderWindow* app);
	void tick(int timeDelta);
	void mouseClicked();
private:
	RenderWindow* app;
	list<GameObject*> gameObjects;
	Room* mainRoom;
	GameUI* gameUI;
};

