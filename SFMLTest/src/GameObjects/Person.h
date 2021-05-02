#pragma once
#include <vector>
#include <map>
#include <string>
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
    map<string, int>* getInventory();
    int getItem(string name);
    void setItem(string name, int value);
    string getStatusPanelString();
private:
    void followPath(int timeDelta);
    int speed;
    int pathIndex;
    Room* currentRoom;
    map<string, int>* inventory;
};

