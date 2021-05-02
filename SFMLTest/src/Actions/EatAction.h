#pragma once
#include "../Action.h"
class EatAction :
    public Action
{
public:
    EatAction();
    Person* eater;
    string foodName;
    void completionEffect();
};

