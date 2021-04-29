#pragma once
#include <vector>
#include "Point.h"
#include "GameEngineUtilities/Path.h"
class Pathfinder
{
public:
	virtual Path* getPath(Point start, Point end) = 0;
	static Path* getGlobalPath(Point start, Room* startingRoom, Point end, Room* endingRoom);
};

