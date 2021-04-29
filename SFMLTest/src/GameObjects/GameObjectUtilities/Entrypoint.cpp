#include "Entrypoint.h"

Entrypoint::Entrypoint(Point internalEntrypoint, Point externalEntrypoint)
{
	this->internalEntrypoint = internalEntrypoint;
	this->externalEntrypoint = externalEntrypoint;
}

Point Entrypoint::getInternalEntrypoint()
{
	return internalEntrypoint;
}

Point Entrypoint::getExternalEntrypoint()
{
	return externalEntrypoint;
}
