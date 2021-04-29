#include "GlobalRoom.h"
#include "../../DataLoader.h"
#include "../../Pathfinders/RightAngleDumbPathfinder.h"

GlobalRoom::GlobalRoom(RenderWindow* app, Point location, float rotation, Room* parentRoom)
    : Room{ app, location, rotation, new RightAngleDumbPathfinder(), DataLoader::globalRoomFootprint, parentRoom }
{
	name = "Global Room";
	Sprite* sprite = new Sprite(*DataLoader::globalRoomTexture);
	sprite->setOrigin(25, 25);
	sprite->setScale(getRoomFootprint()->getXLength(), getRoomFootprint()->getYLength());
	setSprite(sprite);
}

