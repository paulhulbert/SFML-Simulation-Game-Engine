#pragma once
#include <vector>
#include "../Point.h"
#include "PathPoint.h"
using namespace std;

class Room;

class Path
{
public:
	void addPoint(Point point, Room* room);
	vector<PathPoint> points;
};

