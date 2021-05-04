#include "Constants.h"
#include <sstream>

const float Constants::PI = 3.141592;
const int Constants::TILE_LENGTH = 50;

vector<string> Constants::tokenizer(string s, char delimiter)
{
	vector<string> tokens;

    std::stringstream check1(s);

    string intermediate;


    while (getline(check1, intermediate, delimiter))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}