#include "GiveQueryAction.h"

GiveQueryAction::GiveQueryAction()
{
	name = "Querying";
	remainingWork = 100;
}

void GiveQueryAction::tick()
{
	Action::tick();

	if (remainingWork == 0)
	{
		query->response = -2;
	}

	if (!queryGiven)
	{
		receiver->receiveQuery(query);
		queryGiven = true;
	}

	if (query->response >= 0)
	{
		remainingWork = 0;
	}
}
