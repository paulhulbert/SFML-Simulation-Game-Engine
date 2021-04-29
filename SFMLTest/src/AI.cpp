#include "AI.h"

Action* AI::generateAction()
{
	if (owner->getLocation().x == 1050)
	{
		Room* targetRoom = NULL;
		for (list<Room*>::iterator it = owner->getCurrentRoom()->parentRoom->internalRooms.begin(); it != owner->getCurrentRoom()->parentRoom->internalRooms.end(); ++it) {
			if ((*it) != owner->getCurrentRoom())
			{
				targetRoom = (*it);
			}
		}
		if (targetRoom != NULL)
		{
			Action* newAction = new Action();
			newAction->name = "Hi";
			newAction->remainingWork = 30;
			newAction->targetPoint = Point(450, 650);
			newAction->targetRoom = targetRoom;
			//owner->currentPath = Pathfinder::getGlobalPath(owner->getLocation(), owner->getRoom(), Point(1050, 500), targetRoom);
			return newAction;
		}
	} 
	else
	{
		Room* targetRoom = NULL;
		for (list<Room*>::iterator it = owner->getCurrentRoom()->parentRoom->internalRooms.begin(); it != owner->getCurrentRoom()->parentRoom->internalRooms.end(); ++it) {
			if ((*it) != owner->getCurrentRoom())
			{
				targetRoom = (*it);
			}
		}
		if (targetRoom != NULL)
		{
			Action* newAction = new Action();
			newAction->name = "Hi";
			newAction->remainingWork = 30;
			newAction->targetPoint = Point(1050, 500);
			newAction->targetRoom = targetRoom;
			//owner->currentPath = Pathfinder::getGlobalPath(owner->getLocation(), owner->getRoom(), Point(1050, 500), targetRoom);
			return newAction;
		}
	}
	return nullptr;
}
