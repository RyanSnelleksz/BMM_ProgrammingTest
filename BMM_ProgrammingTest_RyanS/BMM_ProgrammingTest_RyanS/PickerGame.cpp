
#include "PickerGame.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Update
// 
// To be run in the program running loop, this is where the inputs and outputs /
// functionality of the game will take place.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PickerGame::Update(bool simulate)
{
    int pInput; // player input

    std::cout << "Please make your pick; Enter a number between 1 and " << prizePool.size() << ": " << '\n' << '\n';

    if (simulate)
    {
        pInput = Random(prizePool.size());
    }
    else
    {
        pInput = GetValidInput();
    }

    Prize selectedPrize = prizePool[pInput - 1]; // Relaying pick to player
    std::cout << "You have picked: " << pInput << " - " << selectedPrize.type << " ";
    if (selectedPrize.value != 0)
    {
        std::cout << selectedPrize.value;
    }
    std::cout << '\n' << '\n';;

    ResolvePick(selectedPrize); //Process Pick
    prizePool.erase(prizePool.begin() + pInput - 1); // -1 since player inputs 1-15 when array is 0-14
    picks -= 1;

    if (picks == 0)
    {
        gameComplete = true;
        std::cout << "Game Over " << credit << '\n';
        std::cout << "Credit: " << credit << '\n' << '\n';
    }
    else
    {
        std::cout << "You have " << picks << " pick/s remaining." << '\n';
        std::cout << "Credit: " << credit  << '\n' << '\n';
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// GetValidInput
// 
// Prompts user for a number between 0 and the prize pool current size.
// It will check if it is a valid input and return it if so, otherwise
// it will prompt again.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int PickerGame::GetValidInput()
{
    int input;

    bool validInput = false;
    while (!validInput)
    {
        if (!(std::cin >> input) || input <= 0 || input > prizePool.size()) //failed to read int
        {
            std::cout << "Invalid input: Please make enter a number between 1 and " << prizePool.size() << ": " << '\n' << '\n';
        }
        else
        {
            validInput = true;
        }
        std::cin.clear(); // cleaning up input for retry
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Random
// 
// Generates a random number between 1 and the given number and returns it.
// Includes 1 and given number in range that can be given.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int PickerGame::Random(int num)
{
    // Use random_device to generate a seed for Mersenne twister engine.
    std::random_device rd{};

    std::mt19937 generator(rd()); // Set the seed
    std::uniform_int_distribution<int> dis(1, num); // Set range

    int randomNum;

    return randomNum = dis(generator);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ShufflePrizePool
// 
// Shuffles positions of prizes in prize pool.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PickerGame::ShufflePrizePool()
{
    for (int i = 0; i < prizePool.size(); i++)
    {
        int randomNum = Random(prizePool.size()) - 1; // - 1 since it generates a num from 1-15 when array is 0-14
        Prize temp = prizePool[i];

        prizePool[i] = prizePool[randomNum];
        prizePool[randomNum] = temp;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// ResolvePick
// 
// Checks what type of prize they player picked and acts accordingly
// 
// Credit: Addes credit to the players credit equal to value of prize
// ExtraPick: Grants extra picks equal to value of prize
// Blank: Does nothing
// Free Game: Gives the player free runs of the game but does nothing in this assessment project
// Stopper: Ends game
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PickerGame::ResolvePick(Prize pick)
{
    if (pick.type == "Credit")
    {
        std::cout << "+" << pick.value << " Credit" << '\n' << '\n';
        credit += pick.value;
    }
    else if (pick.type == "ExtraPick")
    {
        std::cout << "+" << pick.value << " Picks" << '\n' << '\n';
        picks += pick.value;
    }
    else if (pick.type == "Stopper")
    {
        std::cout << "Game Over" << '\n' << '\n';
        std::cout << "Credit: " << credit << '\n';
        gameComplete = true;
    }
    else if (pick.type == "FreeGame")
    {
        std::cout << "+" << pick.value << " Free Games" << '\n' << '\n';
    }
}
