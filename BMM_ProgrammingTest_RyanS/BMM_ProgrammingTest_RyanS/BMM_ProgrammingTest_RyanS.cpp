// BMM_ProgrammingTest_RyanS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PickerGame.h"

int main()
{
    PickerGame pGame = PickerGame();

    pGame.ShufflePrizePool();

    std::cout << "Welcome to the Picker Game!!" << '\n' << '\n';

    std::cout << "You will be presented with " << pGame.GetPrizePool().size() << " hidden and randomized prizes." << '\n' << '\n';

    std::cout << "You will start with 3 picks and can pick until you run out of picks or pick the stopper." << '\n' << '\n';

    std::cout << "You can win free games, credit and extra picks to be used in the same game." << '\n' << '\n';

    bool gameRunning = true;
    while(gameRunning)
    {
        pGame.Update();

        gameRunning = false;
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
