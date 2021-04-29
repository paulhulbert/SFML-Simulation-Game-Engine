#include "StraightLineDumbPathfinder.h"
using namespace std;

Path* StraightLineDumbPathfinder::getPath(Point start, Point end)
{
	Path* path = new Path();
	path->addPoint(Point(end.x, end.y), NULL);
	return path;
}