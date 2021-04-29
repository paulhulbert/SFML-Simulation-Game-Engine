#pragma once
#include "../Point.h"

class Room;

class PathPoint
{
public:
	PathPoint(Point point, Room* room);
	Point point;
	Room* room;
};

