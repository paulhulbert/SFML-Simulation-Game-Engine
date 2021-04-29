#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	int x;
	int y;
	static float distance(Point point1, Point point2);
	float distanceToPoint(Point targetPoint);
	static float angleBetweenPoints(Point origin, Point target);
	float angleToPoint(Point target);
	void translate(int distance, float angle);
	void rotateAroundPoint(Point point, float angle);
};

