#pragma once
#include "../Room.h"
class GlobalRoom :
    public Room
{
public:
    GlobalRoom(RenderWindow* app, Point location, float rotation, Room* parentRoom);
};

