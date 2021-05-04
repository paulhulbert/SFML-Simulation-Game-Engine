#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class Query
{
public:
	Query();
	string name;
	string message;
	int response;
	vector<string> options;
};

