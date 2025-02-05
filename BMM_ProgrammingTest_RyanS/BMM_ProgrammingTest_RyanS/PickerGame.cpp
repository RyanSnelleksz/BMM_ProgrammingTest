
#include "PickerGame.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Update
// 
// To be run in the program running loop, this is where the inputs and outputs /
// functionality of the game will take place.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PickerGame::Update()
{
    int pInput; // player input

    std::cout << "Please make your pick; Enter a number between 1 and " << prizePool.size() << ": " << '\n' << '\n';

    pInput = GetValidInput();

    Prize selectedPrize = prizePool[pInput];
    std::cout << "You have picked: " << selectedPrize.type;
    if (selectedPrize.value != 0)
    {
        std::cout << selectedPrize.value;
    }
    std::cout << '\n' << '\n';;

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
        if (!(std::cin >> input)) //failed to read int
        {
            std::cin.clear(); // cleaning up input for retry
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input: Please make enter a number between 1 and " << prizePool.size() << ": " << '\n' << '\n';
        }
        if (input > 0 && input <= prizePool.size())
        {
            validInput = true;
        }
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
        int randomNum = Random(prizePool.size()) - 1;
        Prize temp = prizePool[i];

        prizePool[i] = prizePool[randomNum];
        prizePool[randomNum] = temp;
    }
}
