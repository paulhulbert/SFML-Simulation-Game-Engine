#include "EatAction.h"

EatAction::EatAction()
{
	name = "Eating";
	remainingWork = 50;
}

void EatAction::completionEffect()
{
	if (eater != NULL)
	{
		eater->setItem(foodName, eater->getItem(foodName) - 1);
	}
}
