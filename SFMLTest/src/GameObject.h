#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include "Point.h"
using namespace sf;
using namespace std;
class GameObject
{
protected:
	RenderWindow *app;
public:
	GameObject(RenderWindow* app, Point location, float rotation);
	virtual void tick(int timeDelta);
	Point getLocation();
	void setLocation(Point location);
	float getRotation();
	void setRotation(float rotation);
	void setSprite(Sprite* sprite);
	Sprite* getSprite();
	virtual void render();
	string name;
	virtual string getStatusPanelString();
private:
	Point location;
	float rotation;
	Sprite* sprite;
};

