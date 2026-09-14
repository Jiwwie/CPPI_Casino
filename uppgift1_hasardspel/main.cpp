#include <iostream>
#include <cstdlib>
#include <random>
#include "Shared.h"
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"
#include "RockPaperScissor.h"

int main()
{
    enum MainMenu
    {
        MainMenu_DiceGame = 1,
        MainMenu_OddOrEven = 2,
        MainMenu_Blackjack = 3,
        MainMenu_RockPaperScissor = 4,
        MainMenu_Statistics = 5,
        MainMenu_LeaveCasino = 6
    };

    int stats[5] =
    {
       GameResult_NoStat,
       GameResult_NoStat,
       GameResult_NoStat,
       GameResult_NoStat,
       GameResult_NoStat
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
            case MainMenu_DiceGame:
            {
                DiceGame::PlayDiceGame(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case MainMenu_OddOrEven:
            {
                OddOrEven::PlayOddOrEven(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case MainMenu_Blackjack:
            {
                Blackjack::PlayBlackjack(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
			case MainMenu_RockPaperScissor:
			{
				//RockPaperScissor::PlayRPS(gameRunning, playerWallet, rewardMult, betAmount, stats);
				break;
			}
            case MainMenu_Statistics:
            {
                SharedFunctions::ShowStatistics(stats);
                break;
            }
            case MainMenu_LeaveCasino:
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