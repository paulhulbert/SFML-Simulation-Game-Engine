#pragma once
#include "GameObjects/Person.h"
#include "Action.h"
#include "GameObjects/Room.h"

class AI
{
public:
	Person* owner;
	Action* generateAction();
};

