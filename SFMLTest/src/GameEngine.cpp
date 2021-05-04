#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "GameObjects/Person.h"
#include "GameObjects/Rooms/GlobalRoom.h"
#include "GameObjects/Rooms/SimpleRoom.h"
#include "Constants.h"
#include "AI.h"
#include "AIs/PlayerCharacterAI.h"
#include <iostream>
using namespace sf;

GameEngine::GameEngine(RenderWindow* app)
{
	this->app = app;
	gameUI = new GameUI(app);

	cameraX = app->getDefaultView().getCenter().x + 30;
	cameraY = app->getDefaultView().getCenter().y;


	mainRoom = new GlobalRoom(app, Point(775, 550), 0, NULL);
	gameObjects.push_back(mainRoom);
	Room* sRoom1 = new SimpleRoom(app, Point(1000, 500), 0, mainRoom);
	sRoom1->name = "sRoom1";
	Room* sRoom2 = new SimpleRoom(app, Point(500, 700), Constants::PI / 2, mainRoom);
	sRoom2->name = "sRoom2";
	Person* person = new Person(app, Point(450, 250), 45);
	person->setCurrentRoom(mainRoom);
	AI* ai = new AI();
	ai->owner = person;
	person->AIs.push_back(ai);


	Person* player = new Person(app, Point(1000, 500), 0);
	player->name = "Player";
	player->setCurrentRoom(sRoom1);
	AI* playerAI = new PlayerCharacterAI();
	playerAI->owner = player;
	player->AIs.push_back(playerAI);
	gameUI->player = player;
}

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

void GameEngine::tick(int timeDelta)
{
	auto mouse_pos = sf::Mouse::getPosition(*app);
	auto translated_pos = app->mapPixelToCoords(mouse_pos, app->getDefaultView());

	if (translated_pos.x < 5)
	{
		cameraX -= 3;
	}
	else if (translated_pos.x > app->getDefaultView().getSize().x - 5)
	{
		cameraX += 3;
	}

	if (translated_pos.y < 5)
	{
		cameraY -= 3;
	}
	else if (translated_pos.y > app->getDefaultView().getSize().y - 5)
	{
		cameraY += 3;
	}


	View view1 = app->getDefaultView();
	view1.setCenter(cameraX, cameraY);
	app->setView(view1);


	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->tick(timeDelta);
	}
	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->render();
	}
	drawGridMesh(app);
	gameUI->render();
}

Room* findRoomSpriteCollider(Room* room, Vector2f position)
{
	for (list<Room*>::iterator it = room->internalRooms.begin(); it != room->internalRooms.end(); ++it) {
		if ((*it)->getSprite()->getGlobalBounds().contains(position))
		{
			return findRoomSpriteCollider((*it), position);
		}
	}

	return room;
}

void GameEngine::mouseClicked()
{
	auto mouse_pos = sf::Mouse::getPosition(*app); 
	auto translated_pos = app->mapPixelToCoords(mouse_pos); 

	if (gameUI->backgroundSprite->getGlobalBounds().contains(app->mapPixelToCoords(mouse_pos, app->getDefaultView())))
	{
		gameUI->mouseClicked();
	}
	else
	{
		Room* clickedRoom = findRoomSpriteCollider(mainRoom, translated_pos);
		if (clickedRoom != NULL)
		{
			Person* targetPerson = NULL;
			for (list<Person*>::iterator it = clickedRoom->containedPeople.begin(); it != clickedRoom->containedPeople.end(); ++it) {
				if ((*it)->getSprite()->getGlobalBounds().contains(translated_pos))
				{
					targetPerson = (*it);
					break;
				}
			}
			if (targetPerson != NULL)
			{
				cout << "In sprite of " << targetPerson->name << endl;
				gameUI->selectedObject = targetPerson;
			}
			else
			{
				cout << "In sprite of " << clickedRoom->name << endl;
				gameUI->selectedObject = clickedRoom;
			}
		}
	}
}
