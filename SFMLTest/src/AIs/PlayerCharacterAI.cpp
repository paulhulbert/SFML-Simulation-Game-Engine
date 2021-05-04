#include <iostream>
#include "PlayerCharacterAI.h"
#include "../Actions/WaitAction.h"
#include "../Queries/LocationQuery.h"
using std::cout;
using std::endl;

Action* PlayerCharacterAI::generateAction()
{
	for (list<Query*>::iterator it = activeQueries.begin(); it != activeQueries.end(); ++it) {
		if ((*it)->response != -1)
		{
			it = activeQueries.erase(it);
			if (it == activeQueries.end())
			{
				break;
			}
		}
	}


	WaitAction* waitAction = new WaitAction();
	waitAction->remainingWork = 5;
	waitAction->targetPoint = owner->getLocation();
	waitAction->targetRoom = owner->getCurrentRoom();
	return waitAction;
}

bool PlayerCharacterAI::handleQuery(Query* query)
{
	activeQueries.push_back(query);
	/*if (debug == 0)
	{
		debug = 1;
		query->response = 0;
	}
	else
	{
		debug = 0;
		query->response = 1;
	}
	cout << "Handled query with location: " << query->options.at(query->response) << endl;*/
    return true;
}
