#pragma once
#include "Point.h"
#include "GameObjects/Room.h"
#include <string>

using std::string;

class Action
{
public:
	string name;
	Point targetPoint;
	int remainingWork;
	Room* targetRoom;
};

