#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <iomanip>
#include <limits>

using namespace std;

struct Prize
{
    string type;
    double value;

    double numWon = 0; // For data collection only

    Prize(string t, double v)
    {
        type = t;
        value = v;
    }
};

struct PickGameData
{
    int picksMade = 0;

    Prize credit500Data = Prize("Credit", 500);
    Prize credit50Data = Prize("Credit", 50);
    Prize freeGame10Data = Prize("FreeGame", 10);
    Prize freeGame5Data = Prize("FreeGame", 5);
    Prize extraPick2Data = Prize("ExtraPick", 2);
    Prize extraPickData = Prize("ExtraPick", 1);
    Prize blankData = Prize("Blank", 0);
    Prize stopperData = Prize("Stopper", 0);

    PickGameData()
    {

    };

    void Add(PickGameData otherGame)
    {
        picksMade += otherGame.picksMade;

        credit500Data.numWon += otherGame.credit500Data.numWon;
        credit50Data.numWon += otherGame.credit50Data.numWon;
        freeGame10Data.numWon += otherGame.freeGame10Data.numWon;
        freeGame5Data.numWon += otherGame.freeGame5Data.numWon;
        extraPick2Data.numWon += otherGame.extraPick2Data.numWon;
        extraPickData.numWon += otherGame.extraPickData.numWon;
        blankData.numWon += otherGame.blankData.numWon;
        stopperData.numWon += otherGame.stopperData.numWon;
    };
};

class PickerGame
{

    vector<Prize> prizePool;
    int picks = 3;
    int credit = 0;

    PickGameData* gameData;

public:

    bool gameComplete = false;

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

        gameData = new PickGameData();

        ShufflePrizePool();
    }

    PickerGame(PickGameData* pGameData)
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

        ShufflePrizePool();

        gameData = pGameData;
    }

    PickerGame(vector<Prize> prizes) // Initialize a game with a custom prize pool
    {
        prizePool = prizes;

        gameData = new PickGameData();

        ShufflePrizePool();
    }

    ~PickerGame() // Need to delete game data
    {
        delete gameData;
    }

    void Update(bool simulate);

    void printPrizePool()
    {
        for (Prize p : prizePool)
        {
            std::cout << p.type << ": " << p.value << std::endl;
        }
    }

    const vector<Prize>& GetPrizePool()
    {
        return prizePool;
    }

    int GetValidInput();

    int Random(int num); // Generates Random Nums between 1 and num

    void ShufflePrizePool(); // Shuffles the prize pool

    void ResolvePick(Prize pick); // Checks the players pick and resolves based on it

    void gameIntro()
    {
        std::cout << "Welcome to the Picker Game!!" << '\n' << '\n';

        std::cout << "You will be presented with " << prizePool.size() << " hidden and randomized prizes." << '\n' << '\n';

        std::cout << "You will start with 3 picks and can pick until you run out of picks or pick the stopper." << '\n' << '\n';

        std::cout << "You can win free games, credit and extra picks to be used in the same game." << '\n' << '\n';
    }
};