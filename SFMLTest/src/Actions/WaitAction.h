#pragma once
#include "../Action.h"
class WaitAction :
    public Action
{
public:
    WaitAction();
    void tick();
};

