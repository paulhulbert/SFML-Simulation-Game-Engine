#include "EatAction.h"

EatAction::EatAction()
{
	name = "Eating";
	remainingWork = 50;
}

void EatAction::tick()
{
	Action::tick();

	if (remainingWork <= 0)
	{
		completionEffect();
	}
}

void EatAction::completionEffect()
{
	if (eater != NULL)
	{
		eater->setItem(foodName, eater->getItem(foodName) - 1);
	}
}
