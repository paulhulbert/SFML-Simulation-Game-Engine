#pragma once
#include "../Query.h"
#include "../Point.h"
class LocationQuery :
    public Query
{
public:
    LocationQuery();
    Point location;
};

