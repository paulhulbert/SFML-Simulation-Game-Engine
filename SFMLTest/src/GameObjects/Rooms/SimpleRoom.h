#pragma once
#include "../Room.h"
class SimpleRoom :
    public Room
{
public:
    SimpleRoom(RenderWindow* app, Point location, float rotation, Room* parentRoom);
};

