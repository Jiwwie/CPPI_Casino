#include <iostream>
#include <cstdlib>
#include <random>
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"
#include "RockPaperScissors.h"
#include "Roulette.h"
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
		MainMenu_Roulette = 5,
        MainMenu_Statistics = 6,
        MainMenu_LeaveCasino = 7
    };

    int stats[5] =
    {
       Statistics::GameResult_NoStat,
       Statistics::GameResult_NoStat,
       Statistics::GameResult_NoStat,
       Statistics::GameResult_NoStat,
       Statistics::GameResult_NoStat
    };

    int activeGame = 0;
	Player::PlayerData player = {};
	Player::TotalEarnings earnings = {};

    Blackjack blackjack;
    DiceGame diceGame;
    OddEven oddOrEven;
    RPS rockPaperScissors;
    Roulette roulette;

    while (player.playing)
    {
        GameFunctions::ShowMainMenu();
        std::cin >> activeGame;
        Player::ClearInputBuffer();

        switch (activeGame)
        {
            case MainMenu_DiceGame:
            {
                diceGame.PlayDiceGame(player, stats, earnings.diceGame);
                break;
            }
            case MainMenu_OddOrEven:
            {
                oddOrEven.PlayOddOrEven(player, stats, earnings.oddOrEven);
                break;
            }
            case MainMenu_Blackjack:
            {
                blackjack.PlayBlackjack(player, stats, earnings.blackjack);
                break;
            }
			case MainMenu_RockPaperScissors:
			{
				rockPaperScissors.PlayRPS(player, stats, earnings.rockPaperScissors);
				break;
			}
			case MainMenu_Roulette:
			{
				roulette.PlayRoulette(player, stats, earnings.roulette);
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