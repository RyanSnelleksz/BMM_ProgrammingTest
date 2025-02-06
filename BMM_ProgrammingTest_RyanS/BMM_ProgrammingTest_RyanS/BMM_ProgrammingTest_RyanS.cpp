// BMM_ProgrammingTest_RyanS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PickerGame.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// OutputAveragesAndProbability
// 
// gData - Game totals
// sCount - How many games
// 
// Takes the above variables and outputs pick average, average credit won
// and probability for each prize.
// 
// Is outputing to console.
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void OutputAveragesAndProbability(PickGameData gData, double sCount)
{
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);

    std::cout << "Results for " << sCount << " games: " << '\n' << '\n';

    double averagePicks = gData.picksMade / sCount;

    std::cout << "Average Picks Made per feature: " << averagePicks << '\n' << '\n';

    std::cout << "Probability for each prize to be picked during a feature: " << '\n' << '\n';

    double creditsWon = (gData.credit500Data.numWon * gData.credit500Data.value) + (gData.credit50Data.numWon * gData.credit50Data.value);
    creditsWon = creditsWon / sCount;

    std::cout << "Average Credits won per game: " << creditsWon << '\n' << '\n';

    std::cout << "Probability for each prize to be picked during a feature: " << '\n' << '\n';

    double credit500 = gData.credit500Data.numWon / sCount;

    std::cout << "Credit 500: " << credit500 << '\n' << '\n';

    double credit50 = gData.credit50Data.numWon / sCount;

    std::cout << "Credit 50: " << credit50 << '\n' << '\n';

    double freeGame10 = gData.freeGame10Data.numWon / sCount;

    std::cout << "10 Free Games: " << freeGame10 << '\n' << '\n';

    double freeGame5 = gData.freeGame5Data.numWon / sCount;

    std::cout << "5 Free Games: " << freeGame5 << '\n' << '\n';

    double extraPick2 = gData.extraPick2Data.numWon / sCount;

    std::cout << "2 Extra Picks: " << extraPick2 << '\n' << '\n';

    double extraPick = gData.extraPickData.numWon / sCount;

    std::cout << "Extra Pick: " << extraPick << '\n' << '\n';

    double blank = gData.blankData.numWon / sCount;

    std::cout << "Blank: " << blank << '\n' << '\n';

    double stopper = gData.stopperData.numWon / sCount;

    std::cout << "Stopper: " << stopper << '\n' << '\n';
}

int main()
{
    PickGameData gameTotals = PickGameData();

    int simulationCount = 1; // How many games we want to simulate << If you want to play manually set to 1 so it doesnt keep going
    for (int i = 0; i < simulationCount; i++)
    {
        PickGameData* pGameData = new PickGameData(); // delete called in pGame destructor

        // Setting up and Introducing Game
        PickerGame pGame = PickerGame(pGameData);
        pGame.gameIntro();

        while (!pGame.gameComplete)
        {
            pGame.Update(false); // True means simulating, put false if you want to play yourself
        }
        gameTotals.Add(*pGameData);
    }
    //OutputAveragesAndProbability(gameTotals, (double)simulationCount);
    std::getchar();
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
