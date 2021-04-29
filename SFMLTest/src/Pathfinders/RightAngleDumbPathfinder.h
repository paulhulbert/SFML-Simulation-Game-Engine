#pragma once
#include "../Pathfinder.h"
class RightAngleDumbPathfinder :
    public Pathfinder
{
public:
    Path* getPath(Point start, Point end);
};

