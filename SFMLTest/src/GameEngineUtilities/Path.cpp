#include "Path.h"
#include "../GameObjects/Room.h"

void Path::addPoint(Point point, Room* room)
{
	points.push_back(PathPoint(point, room));
}
