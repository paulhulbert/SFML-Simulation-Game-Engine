#pragma once
#include <vector>
#include "../GameObject.h"
#include "../Pathfinder.h"

class AI;
class Action;

using namespace std;
class Person :
    public GameObject
{
public:
    Person(RenderWindow* app, Point location, float rotation);
    void tick(int timeDelta);
    virtual void render();
    Path* currentPath;
    Action* currentAction;
    vector<AI*> AIs;
    void setCurrentRoom(Room* room);
    Room* getCurrentRoom();
private:
    void followPath(int timeDelta);
    int speed;
    int pathIndex;
    Room* currentRoom;
};

