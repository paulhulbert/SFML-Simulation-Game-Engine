#pragma once
#include "../Pathfinder.h"
class StraightLineDumbPathfinder :
    public Pathfinder
{
public:
    Path* getPath(Point start, Point end);
};

