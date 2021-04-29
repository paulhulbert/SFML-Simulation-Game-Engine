#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects/GameObjectUtilities/RoomFootprint.h"
using namespace sf;

class DataLoader
{
public:
	static void initialize();
	static Texture* personTexture;
	static Texture* simpleRoomTexture;
	static Texture* globalRoomTexture;
	static Texture* uITexture;


	static RoomFootprint* simpleRoomFootprint;
	static RoomFootprint* globalRoomFootprint;
};

