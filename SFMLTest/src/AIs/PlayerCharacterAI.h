#pragma once
#include "../AI.h"
#include <list>
using std::list;
class PlayerCharacterAI :
	public AI
{
public:
	Action* generateAction();
	bool handleQuery(Query* query);
	list<Query*> activeQueries;
private:
	int debug = 0;
};

