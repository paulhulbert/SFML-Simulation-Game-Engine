#include "DataLoader.h"
using namespace std;

Texture* DataLoader::personTexture = NULL;
Texture* DataLoader::simpleRoomTexture = NULL;
Texture* DataLoader::globalRoomTexture = NULL;
Texture* DataLoader::uITexture = NULL;



RoomFootprint* DataLoader::simpleRoomFootprint = NULL;
RoomFootprint* DataLoader::globalRoomFootprint = NULL;

RoomFootprint* createSimpleRoomFootprint()
{
	RoomFootprint* footprint = new RoomFootprint(5, 5);
	for (int x = 0; x < footprint->getXLength(); x++)
	{
		for (int y = 0; y < footprint->getYLength(); y++)
		{
			footprint->setTileValueAt(x, y, 'i');
		}
	}
	footprint->setTileValueAt(4, 2, 'e');
	return footprint;
}

RoomFootprint* createGlobalRoomFootprint()
{
	RoomFootprint* footprint = new RoomFootprint(20, 15);
	for (int x = 0; x < footprint->getXLength(); x++)
	{
		for (int y = 0; y < footprint->getYLength(); y++)
		{
			footprint->setTileValueAt(x, y, 'i');
		}
	}
	footprint->setTileValueAt(14, 14, 'e');
	return footprint;
}

void createFootprints()
{
	DataLoader::simpleRoomFootprint = createSimpleRoomFootprint();
	DataLoader::globalRoomFootprint = createGlobalRoomFootprint();
}


Texture* loadTexture(string filePath)
{
	Texture* texture = new Texture();
	texture->loadFromFile(filePath);
	texture->setSmooth(true);
	return texture;
}


void DataLoader::initialize()
{
	personTexture = loadTexture("images/Person.png");
	simpleRoomTexture = loadTexture("images/BrownRectangle.png");
	globalRoomTexture = loadTexture("images/GreenRectangle.png");
	uITexture = loadTexture("images/TanRectangle.png");
	createFootprints();
}
