#pragma once
#include "GameObjects/Person.h"
#include "Action.h"
#include "GameObjects/Room.h"
#include "Query.h"

class AI
{
public:
	AI();
	Person* owner;
	virtual Action* generateAction();
	virtual bool handleQuery(Query* query);
private:
	Query* debugQuery;
};

