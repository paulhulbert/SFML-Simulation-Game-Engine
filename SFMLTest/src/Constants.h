#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class Constants
{
public:
	static const float PI;
	static const int TILE_LENGTH;

	static vector<string> tokenizer(string s, char delimiter);
};

