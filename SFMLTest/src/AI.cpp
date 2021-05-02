#include "AI.h"
#include "Actions/EatAction.h"

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
			EatAction* newAction = new EatAction();
			newAction->targetPoint = Point(450, 650);
			newAction->targetRoom = targetRoom;
			newAction->eater = owner;
			newAction->foodName = "Food";
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
			EatAction* newAction = new EatAction();
			newAction->targetPoint = Point(1050, 500);
			newAction->targetRoom = targetRoom;
			newAction->eater = owner;
			newAction->foodName = "Food";
			return newAction;
		}
	}
	return nullptr;
}
