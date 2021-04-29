#pragma once
/**
* char value key:
* 0 == not part of the room
* i == part of the room
* e == entrypoint (entrypoints must not be on a corner of a building)
*/
class RoomFootprint
{
public:
	RoomFootprint(int xLength, int yLength);
	char getTileValueAt(int x, int y);
	void setTileValueAt(int x, int y, char value);
	int getXLength();
	int getYLength();
private:
	int xLength;
	int yLength;
	char *grid;
};

