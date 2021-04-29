#pragma once
#include <list>
#include "../GameObject.h"
#include "../Pathfinder.h"
#include "GameObjectUtilities/RoomFootprint.h"
#include "Person.h"
#include "GameObjectUtilities/Entrypoint.h"
using namespace std;
class Room :
    public GameObject
{
public:
    Room(RenderWindow* app, Point location, float rotation, Pathfinder* pathfinder, RoomFootprint* footprint, Room* parentRoom);
    list<Room*> internalRooms;
    list<Person*> containedPeople;
    Room* parentRoom;
    RoomFootprint* getRoomFootprint();
    Pathfinder* getPathfinder();  
    vector<Entrypoint*> getEntrypoints();
    virtual void tick(int timeDelta);
    virtual void render();
private:
    Pathfinder* pathfinder;
    RoomFootprint* footprint;
    vector<Entrypoint*> entrypoints;
    void identifyEntrypoints();
};

