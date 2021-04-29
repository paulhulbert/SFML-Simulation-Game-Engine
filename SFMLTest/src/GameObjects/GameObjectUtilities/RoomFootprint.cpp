#include "RoomFootprint.h"

RoomFootprint::RoomFootprint(int xLength, int yLength)
{
	this->xLength = xLength;
	this->yLength = yLength;
	grid = new char[xLength * yLength];
	for (int i= 0; i < xLength * yLength; i++)
	{
		grid[i] = '0';
	}
}

char RoomFootprint::getTileValueAt(int x, int y)
{
	return grid[y * xLength + x];
}

void RoomFootprint::setTileValueAt(int x, int y, char value)
{
	grid[y * xLength + x] = value;
}

int RoomFootprint::getXLength()
{
	return xLength;
}

int RoomFootprint::getYLength()
{
	return yLength;
}
