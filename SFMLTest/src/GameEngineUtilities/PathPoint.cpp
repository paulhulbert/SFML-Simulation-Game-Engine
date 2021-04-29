#include "PathPoint.h"
#include "../GameObjects/Room.h"

PathPoint::PathPoint(Point point, Room* room)
{
	this->point = point;
	this->room = room;
}
