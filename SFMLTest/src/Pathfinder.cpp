#include <vector>
#include "Pathfinder.h"
#include "GameObjects/Room.h"
#include <iostream>
using namespace std;

Path* Pathfinder::getGlobalPath(Point start, Room* startingRoom, Point end, Room* endingRoom)
{
	vector<Room*> startingRoomPath;
	vector<Room*> endingRoomPath;

	Room* roomTracer = startingRoom;

	while (roomTracer != NULL)
	{
		startingRoomPath.push_back(roomTracer);
		roomTracer = roomTracer->parentRoom;
	}

	roomTracer = endingRoom;

	while (roomTracer != NULL)
	{
		endingRoomPath.push_back(roomTracer);
		roomTracer = roomTracer->parentRoom;
	}

	int startingConvergenceIndex = -1;
	int endingConvergenceIndex = -1;

	for (int endIndex = 0; endIndex < endingRoomPath.size() && endingConvergenceIndex == -1; endIndex++)
	{
		for (int startIndex = 0; startIndex < startingRoomPath.size() && startingConvergenceIndex == -1; startIndex++)
		{
			if (endingRoomPath.at(endIndex) == startingRoomPath.at(startIndex))
			{
				startingConvergenceIndex = startIndex;
				endingConvergenceIndex = endIndex;
			}
		}
	}
	
	Point* currentPoint = &start;
	Path* finalPath = new Path();

	for (int i = 0; i < startingConvergenceIndex; i++)
	{
		Path* roomPath = startingRoomPath.at(i)->getPathfinder()->getPath(*currentPoint, startingRoomPath.at(i)->getEntrypoints().at(0)->getInternalEntrypoint());

		for (int j = 0; j < roomPath->points.size(); j++)
		{
			finalPath->points.push_back(PathPoint(Point(roomPath->points.at(j).point.x, roomPath->points.at(j).point.y), NULL));
		}

		finalPath->points.push_back(PathPoint(startingRoomPath.at(i)->getEntrypoints().at(0)->getExternalEntrypoint(), startingRoomPath.at(i + 1)));
		Point tempPoint = startingRoomPath.at(i)->getEntrypoints().at(0)->getExternalEntrypoint();
		currentPoint = &tempPoint;
	}

	for (int i = endingConvergenceIndex; i > 0; i--)
	{
		Path* roomPath = endingRoomPath.at(i)->getPathfinder()->getPath(*currentPoint, endingRoomPath.at(i - 1)->getEntrypoints().at(0)->getExternalEntrypoint());

		for (int j = 0; j < roomPath->points.size(); j++)
		{
			finalPath->points.push_back(PathPoint(Point(roomPath->points.at(j).point.x, roomPath->points.at(j).point.y), NULL));
		}

		finalPath->points.push_back(PathPoint(endingRoomPath.at(i - 1)->getEntrypoints().at(0)->getInternalEntrypoint(), endingRoomPath.at(i - 1)));
		Point tempPoint = endingRoomPath.at(i - 1)->getEntrypoints().at(0)->getInternalEntrypoint();
		currentPoint = &tempPoint;
	}

	Path* lastPath = endingRoomPath.at(0)->getPathfinder()->getPath(*currentPoint, end);

	for (int k = 0; k < lastPath->points.size(); k++)
	{
		finalPath->points.push_back(PathPoint(Point(lastPath->points.at(k).point.x, lastPath->points.at(k).point.y), NULL));
	}

	return finalPath;
}
