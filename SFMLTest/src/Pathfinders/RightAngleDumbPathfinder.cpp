#include "RightAngleDumbPathfinder.h"
using namespace std;

Path* RightAngleDumbPathfinder::getPath(Point start, Point end)
{
	Path* path = new Path();
	path->addPoint(Point(end.x, start.y), NULL);
	path->addPoint(Point(end.x, end.y), NULL);
	return path;
}