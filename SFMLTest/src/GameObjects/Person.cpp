#include "Person.h"
#include "../Pathfinders/RightAngleDumbPathfinder.h"
#include <iostream>
#include "../Constants.h"
#include "../DataLoader.h"
#include "Room.h"
#include "../AI.h"
#include "../Action.h"

Person::Person(RenderWindow* app, Point location, float rotation)
	:GameObject{app, location, rotation}
{
	speed = 2;
	pathIndex = 0;
	currentPath = NULL;
	currentRoom = NULL;
	currentAction = NULL;

	Sprite* sprite = new Sprite(*DataLoader::personTexture);
	sprite->setOrigin(25, 25);
	setSprite(sprite);
}

void Person::setCurrentRoom(Room* room)
{
	currentRoom = room;
	room->containedPeople.push_back(this);
}

Room* Person::getCurrentRoom()
{
	return currentRoom;
}

void Person::followPath(int timeDelta)
{
	if (currentPath != NULL)
	{
		int remainingMovementDistance = speed;

		while (remainingMovementDistance > 0)
		{
			Point currentLocation = getLocation();
			Point nextPathPointLocation = currentPath->points.at(pathIndex).point;
			float rotationToTarget = currentLocation.angleToPoint(nextPathPointLocation);
			float distanceToTarget = currentLocation.distanceToPoint(nextPathPointLocation);
			if (distanceToTarget > remainingMovementDistance)
			{
				currentLocation.translate(remainingMovementDistance, rotationToTarget);
				setLocation(currentLocation);
				remainingMovementDistance = 0;
			}
			else
			{
				if (currentPath->points.at(pathIndex).room != NULL)
				{
					setCurrentRoom(currentPath->points.at(pathIndex).room);
				}
				setLocation(nextPathPointLocation);
				remainingMovementDistance -= distanceToTarget;
				if (currentPath->points.size() - 1 > pathIndex)
				{
					pathIndex++;
				}
				else
				{
					pathIndex = 0;
					currentPath = NULL;
					remainingMovementDistance = 0;
				}
			}
			setRotation(rotationToTarget);
		}
	}
	else
	{
		//currentPath = pathfinder->getPath(getLocation(), Point(100, 100));
		setRotation(getRotation() + Constants::PI / 200);
	}
}

void Person::tick(int timeDelta)
{
	if (currentAction == NULL)
	{
		for (int i = 0; i < AIs.size(); i++)
		{
			currentAction = AIs.at(i)->generateAction();
			if (currentAction != NULL)
			{
				currentPath = Pathfinder::getGlobalPath(getLocation(), getCurrentRoom(), currentAction->targetPoint, currentAction->targetRoom);
				break;
			}
		}
	}
	else
	{
		if (getLocation().x == currentAction->targetPoint.x && getLocation().y == currentAction->targetPoint.y)
		{
			currentAction->remainingWork -= 1;
			if (currentAction->remainingWork <= 0)
			{
				currentAction = NULL;
			}
		}
	}

	followPath(timeDelta);

	GameObject::tick(timeDelta);
}

void Person::render()
{
	GameObject::render();

	if (currentPath != NULL)
	{
		sf::VertexArray lines(sf::LinesStrip, 0);

		lines.append(sf::Vector2f(getLocation().x, getLocation().y));

		for (int i = pathIndex; i < currentPath->points.size(); i++)
		{
			lines.append(sf::Vector2f(currentPath->points.at(i).point.x, currentPath->points.at(i).point.y));

			CircleShape circle;
			circle.setRadius(5);
			circle.setOutlineColor(sf::Color::Black);
			circle.setOutlineThickness(2);
			circle.setPosition(currentPath->points.at(i).point.x - 5, currentPath->points.at(i).point.y - 5);
			app->draw(circle);
		}

		app->draw(lines);

	}
}
