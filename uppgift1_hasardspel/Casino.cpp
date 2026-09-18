#include <iostream>
#include <random>
#include "Casino.h"
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"
#include "RockPaperScissors.h"
#include "Roulette.h"
#include "Misc.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

void Casino::GetMainMenu(Player::PlayerData& player)
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
    while (player.playing)
    {
        GameFunctions::ShowMainMenuText();
        std::cin >> activeGame;
        Player::ClearInputBuffer();

        switch (activeGame)
        {
        case MainMenu_DiceGame:
        {
            myDiceGame.PlayDiceGame(player, stats);
            break;
        }
        case MainMenu_OddOrEven:
        {
            myOddOrEven.PlayOddOrEven(player, stats);
            break;
        }
        case MainMenu_Blackjack:
        {
            myBlackjack.PlayBlackjack(player, stats);
            break;
        }
        case MainMenu_RockPaperScissors:
        {
            myRockPaperScissors.PlayRPS(player, stats);
            break;
        }
        case MainMenu_Roulette:
        {
            myRoulette.PlayRoulette(player, stats);
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