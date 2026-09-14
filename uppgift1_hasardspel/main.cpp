#include <iostream>
#include <cstdlib>
#include <random>
#include "Shared.h"
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"

int main()
{
    enum ActiveGame
    {
		ActiveGame_DiceGame = 1,
		ActiveGame_OddOrEven = 2,
		ActiveGame_Blackjack = 3,
		ActiveGame_Statistics = 4,
		ActiveGame_LeaveCasino = 5
    };

    int stats[5] =
    {
       0,
       0,
       0,
       0,
       0
    };

    int activeGame = 0;
    bool gameRunning = true;
    int playerWallet = 1000;
    int rewardMult = 2;
    int betAmount = 0;

    while (gameRunning)
    {
        SharedFunctions::ShowMainMenu();
        std::cin >> activeGame;
        SharedFunctions::ClearInputBuffer();

        switch (activeGame)
        {
            case ActiveGame_DiceGame:
            {
                DiceGame::PlayDiceGame(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_OddOrEven:
            {
                OddOrEven::PlayOddOrEven(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_Blackjack:
            {
                Blackjack::PlayBlackjack(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_Statistics:
            {
                SharedFunctions::ShowStatistics(stats);
                break;
            }
            case ActiveGame_LeaveCasino:
            {
                system("cls");
                std::cout << "\nYou left the casino with " << playerWallet << "kr to your name.\n\n\n";
                system("pause");
                gameRunning = false;
                break;
            }
            default: 
            {
                break;
            }
        }
    }
}