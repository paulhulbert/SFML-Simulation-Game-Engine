#include "GameObject.h"
#include "Constants.h"


GameObject::GameObject(RenderWindow* app, Point location, float rotation)
{
	setLocation(location);
	setRotation(rotation);
	this->app = app;
	name = "Game Object";
}

void GameObject::tick(int timeDelta)
{
}

Point GameObject::getLocation()
{
	return location;
}

void GameObject::setLocation(Point location)
{
	this->location = location;
}

void GameObject::render()
{
	if (sprite != NULL)
	{
		sprite->setPosition(getLocation().x, getLocation().y);
		sprite->setRotation((getRotation() * 180 / Constants::PI));
		app->draw(*sprite);
	}
}

string GameObject::getStatusPanelString()
{
	return string();
}

void GameObject::setSprite(Sprite* sprite)
{
	this->sprite = sprite;
}

Sprite* GameObject::getSprite()
{
	return sprite;
}

float GameObject::getRotation()
{
	return rotation;
}

void GameObject::setRotation(float rotation)
{
	while (rotation >= Constants::PI * 2)
	{
		rotation -= Constants::PI * 2;
	}
	while (rotation < 0)
	{
		rotation += Constants::PI * 2;
	}
	this->rotation = rotation;
}
