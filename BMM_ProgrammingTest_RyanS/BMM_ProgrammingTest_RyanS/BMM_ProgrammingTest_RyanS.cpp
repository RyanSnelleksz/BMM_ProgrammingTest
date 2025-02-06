// BMM_ProgrammingTest_RyanS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PickerGame.h"

int main()
{
    PickGameData gameTotals = PickGameData();

    int simulationCount = 2; // How many games we want to simulate << If you want to play manually set to 1 so it doesnt keep going
    for (int i = 0; i < simulationCount; i++)
    {
        PickGameData* pGameData = new PickGameData(); // delete called in pGame destructor

        // Setting up and Introducing Game
        PickerGame pGame = PickerGame(pGameData);
        pGame.gameIntro();

        while (!pGame.gameComplete)
        {
            pGame.Update(true); // True means simulating, put false if you want to play yourself
        }
        gameTotals.Add(*pGameData);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
