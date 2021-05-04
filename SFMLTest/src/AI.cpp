#include "AI.h"
#include "Actions/EatAction.h"
#include "Actions/GiveQueryAction.h"
#include "Query.h"
#include "Constants.h"

AI::AI()
{
	debugQuery = NULL;
	owner = NULL;
}

Action* AI::generateAction()
{
	if (owner->getLocation().y != 250)
	{
		Room* targetRoom = owner->getRoomByName("Global Room");
		if (targetRoom != NULL)
		{
			if (debugQuery == NULL || debugQuery->response < 0)
			{
				EatAction* newAction = new EatAction();
				newAction->targetPoint = Point(450, 650);
				newAction->targetRoom = targetRoom;
				newAction->eater = owner;
				newAction->foodName = "Food";
				return newAction;
			}
			else
			{
				EatAction* newAction = new EatAction();
				newAction->targetPoint = Point(stoi(Constants::tokenizer(debugQuery->options.at(debugQuery->response), ',').at(0)), stoi(Constants::tokenizer(debugQuery->options.at(debugQuery->response), ',').at(1)));
				newAction->targetRoom = targetRoom;
				newAction->eater = owner;
				newAction->foodName = "Food";
				debugQuery = nullptr;
				return newAction;
			}
		}
	} 
	else
	{
		Room* targetRoom = owner->getRoomByName("sRoom1");
		if (targetRoom != NULL)
		{
			GiveQueryAction* newAction = new GiveQueryAction();
			newAction->targetPoint = Point(1050, 500);
			newAction->targetRoom = targetRoom;
			newAction->giver = owner;
			newAction->receiver = targetRoom->containedPeople.front();
			newAction->query = new Query();
			debugQuery = newAction->query;
			debugQuery->options.push_back("350, 250");
			debugQuery->options.push_back("600, 250");
			return newAction;
		}
	}
	return nullptr;
}

bool AI::handleQuery(Query* query)
{
	return false;
}
