#include "Room.h"
#include "../Constants.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;

Room::Room(RenderWindow* app, Point location, float rotation, Pathfinder* pathfinder, RoomFootprint* footprint, Room* parentRoom)
	:GameObject{ app, location, rotation }
{
	this->pathfinder = pathfinder;
	this->footprint = footprint;
	this->parentRoom = parentRoom;
	identifyEntrypoints();

	if (parentRoom != NULL)
	{
		parentRoom->internalRooms.push_back(this);
	}
}

void Room::tick(int timeDelta)
{
	GameObject::tick(timeDelta);

	for (list<Room*>::iterator it = internalRooms.begin(); it != internalRooms.end(); ++it) {
		(*it)->tick(timeDelta);
	}
	for (list<Person*>::iterator it = containedPeople.begin(); it != containedPeople.end(); ++it) {
		(*it)->tick(timeDelta);
		if ((*it)->getCurrentRoom() != this)
		{
			it = containedPeople.erase(it);
			if (it == containedPeople.end())
			{
				break;
			}
		}
	}
}

void Room::render()
{
	GameObject::render();

	for (list<Room*>::iterator it = internalRooms.begin(); it != internalRooms.end(); ++it) {
		(*it)->render();
	}
	for (list<Person*>::iterator it = containedPeople.begin(); it != containedPeople.end(); ++it) {
		(*it)->render();
	}

	// TODO: Remove this code
	for (int i = 0; i < entrypoints.size(); i++) {
		RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(10, 10));
		rectangle.setOutlineColor(sf::Color::Blue);
		rectangle.setOutlineThickness(2);
		rectangle.setPosition(entrypoints.at(i)->getInternalEntrypoint().x - 5, entrypoints.at(i)->getInternalEntrypoint().y - 5);
		app->draw(rectangle);
		rectangle.setOutlineColor(sf::Color::Green);
		rectangle.setPosition(entrypoints.at(i)->getExternalEntrypoint().x - 5, entrypoints.at(i)->getExternalEntrypoint().y - 5);
		app->draw(rectangle);

		VertexArray lines(LinesStrip, 0);
		lines.append(Vector2f(entrypoints.at(i)->getInternalEntrypoint().x, entrypoints.at(i)->getInternalEntrypoint().y));
		lines.append(Vector2f(entrypoints.at(i)->getExternalEntrypoint().x, entrypoints.at(i)->getExternalEntrypoint().y));
		lines[0].color = Color::Blue;
		lines[1].color = Color::Green;
		app->draw(lines);
	}
}

RoomFootprint* Room::getRoomFootprint()
{
	return footprint;
}

Pathfinder* Room::getPathfinder()
{
	return pathfinder;
}

vector<Entrypoint*> Room::getEntrypoints()
{
	return entrypoints;
}

void Room::identifyEntrypoints()
{
	list<Entrypoint> entrypointList;

	int xLength = getRoomFootprint()->getXLength();
	int yLength = getRoomFootprint()->getYLength();


	for (int x = 0; x < xLength; x++)
	{
		for (int y = 0; y < yLength; y++)
		{
			if (getRoomFootprint()->getTileValueAt(x, y) == 'e')
			{
				int externalEntrypointX;
				int externalEntrypointY;
				if (x == 0 || getRoomFootprint()->getTileValueAt(x - 1, y) == '0')
				{
					externalEntrypointX = x - 1;
					externalEntrypointY = y;
				} 
				else if (x == xLength - 1 || getRoomFootprint()->getTileValueAt(x + 1, y) == '0')
				{
					externalEntrypointX = x + 1;
					externalEntrypointY = y;
				}
				else if (y == 0 || getRoomFootprint()->getTileValueAt(x, y - 1) == '0')
				{
					externalEntrypointX = x;
					externalEntrypointY = y - 1;
				}
				else if (y == yLength - 1 || getRoomFootprint()->getTileValueAt(x, y + 1) == '0')
				{
					externalEntrypointX = x;
					externalEntrypointY = y + 1;
				}
				else
				{
					throw "Failed to find external entrypoint";
				}

				entrypointList.push_back(Entrypoint(Point(x, y), Point(externalEntrypointX, externalEntrypointY)));
			}
		}
	}

	Point centerOfFootprint((xLength - 1) * Constants::TILE_LENGTH / 2, (yLength - 1) * Constants::TILE_LENGTH / 2);
	for (list<Entrypoint>::iterator it = entrypointList.begin(); it != entrypointList.end(); ++it) {
		Point internalEntrypoint = it->getInternalEntrypoint();
		Point externalEntrypoint = it->getExternalEntrypoint();
		internalEntrypoint.x *= Constants::TILE_LENGTH;
		internalEntrypoint.y *= Constants::TILE_LENGTH;
		externalEntrypoint.x *= Constants::TILE_LENGTH;
		externalEntrypoint.y *= Constants::TILE_LENGTH;

		internalEntrypoint.rotateAroundPoint(centerOfFootprint, getRotation());
		externalEntrypoint.rotateAroundPoint(centerOfFootprint, getRotation());

		internalEntrypoint.x += getLocation().x - centerOfFootprint.x;
		internalEntrypoint.y += getLocation().y - centerOfFootprint.y;
		externalEntrypoint.x += getLocation().x - centerOfFootprint.x;
		externalEntrypoint.y += getLocation().y - centerOfFootprint.y;

		entrypoints.push_back(new Entrypoint(internalEntrypoint, externalEntrypoint));
	}
}
