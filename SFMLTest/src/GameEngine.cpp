#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "GameObjects/Person.h"
#include "GameObjects/Rooms/GlobalRoom.h"
#include "GameObjects/Rooms/SimpleRoom.h"
#include "Constants.h"
#include "AI.h"
#include <iostream>
using namespace sf;

GameEngine::GameEngine(RenderWindow* app)
{
	this->app = app;
	mainRoom = new GlobalRoom(app, Point(775, 550), 0, NULL);
	gameObjects.push_back(mainRoom);
	Room* sRoom1 = new SimpleRoom(app, Point(1000, 500), 0, mainRoom);
	Room* sRoom2 = new SimpleRoom(app, Point(500, 700), Constants::PI / 2, mainRoom);
	Person* person = new Person(app, Point(450, 650), 45);
	person->setCurrentRoom(sRoom2);
	AI* ai = new AI();
	ai->owner = person;
	person->AIs.push_back(ai);
}

void GameEngine::tick(int timeDelta)
{
	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->tick(timeDelta);
	}
	for (list<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->render();
	}
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
		}
		else
		{
			cout << "In sprite of " << clickedRoom->name << endl;
		}
	}
}
