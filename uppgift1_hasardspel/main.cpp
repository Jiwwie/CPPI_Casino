#include <iostream>
#include <cstdlib>
#include <random>
#include "Shared.h"
#include "Structs.h"
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"
#include "RockPaperScissors.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

int main()
{
    enum MainMenu
    {
        MainMenu_DiceGame = 1,
        MainMenu_OddOrEven = 2,
        MainMenu_Blackjack = 3,
        MainMenu_RockPaperScissors = 4,
        MainMenu_Statistics = 5,
        MainMenu_LeaveCasino = 6
    };

    int stats[5] =
    {
       Shared::GameResult_NoStat,
       Shared::GameResult_NoStat,
       Shared::GameResult_NoStat,
       Shared::GameResult_NoStat,
       Shared::GameResult_NoStat
    };

    int activeGame = 0;

	//Namespace, struct, instance of struct
	Player::Player player = {};
	Player::TotalEarnings earnings = {};

    while (player.playing)
    {
        Shared::ShowMainMenu();
        std::cin >> activeGame;
        Player::ClearInputBuffer();

        switch (activeGame)
        {
            case MainMenu_DiceGame:
            {
                DiceGame::PlayDiceGame(player, stats, earnings.DiceGame);
                break;
            }
            case MainMenu_OddOrEven:
            {
                OddOrEven::PlayOddOrEven(player, stats, earnings.OddOrEven);
                break;
            }
            case MainMenu_Blackjack:
            {
                Blackjack::PlayBlackjack(player, stats, earnings.Blackjack);
                break;
            }
			case MainMenu_RockPaperScissors:
			{
				RockPaperScissors::PlayRPS(player, stats, earnings.RockPaperScissors);
				break;
			}
            case MainMenu_Statistics:
            {
                Statistics::ShowStatistics(stats);
                break;
            }
            case MainMenu_LeaveCasino:
            {
                system("cls");
                std::cout << "\nYou left the casino with " << player.wallet << "kr to your name.\n\n\n";
                system("pause");
                player.playing = false;
                break;
            }
            default: 
            {
                break;
            }
        }
    }
}