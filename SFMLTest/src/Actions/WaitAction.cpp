#include "WaitAction.h"

WaitAction::WaitAction()
{
	name = "Waiting";
	remainingWork = 50;
}

void WaitAction::tick()
{
	Action::tick();
}
