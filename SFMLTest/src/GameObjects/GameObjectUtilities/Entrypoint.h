#pragma once
#include "../../Point.h"
class Entrypoint
{
public:
	Entrypoint(Point internalEntrypoint, Point externalEntrypoint);
	Point getInternalEntrypoint();
	Point getExternalEntrypoint();
private:
	Point internalEntrypoint;
	Point externalEntrypoint;
};

