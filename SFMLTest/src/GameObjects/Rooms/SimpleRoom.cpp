#include "SimpleRoom.h"
#include "../../DataLoader.h"
#include "../../Pathfinders/RightAngleDumbPathfinder.h"

SimpleRoom::SimpleRoom(RenderWindow* app, Point location, float rotation, Room* parentRoom)
    :Room{ app, location, rotation, new RightAngleDumbPathfinder(), DataLoader::simpleRoomFootprint, parentRoom }
{
	name = "Simple Room";
	Sprite* sprite = new Sprite(*DataLoader::simpleRoomTexture);
	sprite->setScale(getRoomFootprint()->getXLength(), getRoomFootprint()->getYLength());
	sprite->setOrigin(25, 25);
	setSprite(sprite);
}
