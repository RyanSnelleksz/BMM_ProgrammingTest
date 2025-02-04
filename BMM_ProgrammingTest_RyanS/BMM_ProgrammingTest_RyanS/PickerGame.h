#pragma once

#include <string>
#include <vector>

using namespace std;

struct Prize
{
    string type;
    int value;

    Prize(string t, int v)
    {
        type = t;
        value = v;
    }
};

class PickerGame
{

    vector<Prize> prizePool;

public:

    PickerGame() // Initialize a game with the default prize pool
    {
        prizePool.push_back(Prize("Credit", 500));
        prizePool.push_back(Prize("Credit", 50));
        prizePool.push_back(Prize("Credit", 50));
        prizePool.push_back(Prize("FreeGame", 10));
        prizePool.push_back(Prize("FreeGame", 5));
        prizePool.push_back(Prize("FreeGame", 5));
        prizePool.push_back(Prize("ExtraPick", 2));
        prizePool.push_back(Prize("ExtraPick", 2));
        prizePool.push_back(Prize("ExtraPick", 1));
        prizePool.push_back(Prize("Blank", 0));
        prizePool.push_back(Prize("Blank", 0));
        prizePool.push_back(Prize("Blank", 0));
        prizePool.push_back(Prize("Blank", 0));
        prizePool.push_back(Prize("Blank", 0));
        prizePool.push_back(Prize("Stopper", 0));
    }
    PickerGame(vector<Prize> prizes) // Initialize a game with a custom prize pool
    {
        prizePool = prizes;
    }

};