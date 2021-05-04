#pragma once
#include "../Action.h"
#include "../Query.h"
class GiveQueryAction :
    public Action
{
public:
    GiveQueryAction();
    Person* giver;
    Person* receiver;
    Query* query;
    void tick();
private:
    bool queryGiven = false;
};

