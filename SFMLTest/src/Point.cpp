#include "Point.h"
#include <cmath>

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

float Point::distance(Point point1, Point point2)
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

float Point::distanceToPoint(Point targetPoint)
{
	return Point::distance(*this, targetPoint);
}

float Point::angleBetweenPoints(Point origin, Point target)
{
	return atan2(target.y - origin.y, target.x - origin.x);
}

float Point::angleToPoint(Point target)
{
	return Point::angleBetweenPoints(*this, target);
}

void Point::translate(int distance, float angle)
{
	x += distance * cos(angle);
	y += distance * sin(angle);
}

void Point::rotateAroundPoint(Point point, float angle)
{
	{
		float s = sin(angle);
		float c = cos(angle);

		// translate point back to origin:
		x -= point.x;
		y -= point.y;

		// rotate point
		int xnew = round(x * c - y * s);
		int ynew = round(x * s + y * c);

		// translate point back:
		x = xnew + point.x;
		y = ynew + point.y;
	}
}
