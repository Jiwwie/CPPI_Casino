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

void Casino::GetMainMenu(Player::PlayerData& aPlayer)
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
    while (aPlayer.playing)
    {
        GameFunctions::ShowMainMenuText();
        std::cin >> activeGame;
        Player::ClearInputBuffer();

        switch (activeGame)
        {
        case MainMenu_DiceGame:
        {
            std::cout << "\nWill you play high or low stakes?\n";
            std::cout << "1. Low\n";
            std::cout << "2. High\n";

            aPlayer.input = Player::GetPlayerNum(aPlayer.input, 2, 1);
            switch (aPlayer.input)
            {
                case 1: 
                {
                    myDiceGameLow.PlayDiceGame(aPlayer, stats);
                    break;
                }
                case 2:
                {
                    myDiceGameHigh.PlayDiceGame(aPlayer, stats);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case MainMenu_OddOrEven:
        {
            myOddOrEven.PlayOddOrEven(aPlayer, stats);
            break;
        }
        case MainMenu_Blackjack:
        {
            myBlackjack.PlayBlackjack(aPlayer, stats);
            break;
        }
        case MainMenu_RockPaperScissors:
        {
            myRockPaperScissors.PlayRPS(aPlayer, stats);
            break;
        }
        case MainMenu_Roulette:
        {
            myRoulette.PlayRoulette(aPlayer, stats);
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
            std::cout << Player::GetUsername() << "\n left the casino with " << aPlayer.wallet << "kr.\n\n\n";
            system("pause");
            aPlayer.playing = false;
            break;
        }
        default:
        {
            break;
        }
        }
    }
}