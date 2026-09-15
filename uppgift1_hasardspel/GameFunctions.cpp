#include <iostream>
#include "Player.h"

namespace GameFunctions
{
    void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult)
    {
        enum IntroKey
        {
            IntroKey_DiceGame = 1,
            IntroKey_OddOrEven = 2,
            IntroKey_Blackjack = 3,
            IntroKey_RockPaperScissors = 4
        };

        system("cls");
        std::cout << " =======================\n";
        std::cout << "||       CASINO        ||\n";
        std::cout << " =======================\n\n";

        std::cout << "You have " << aPlayerWallet << "kr \n";
        std::cout << "Reward multiplier: X" << aRewardMult << "\n\n";

        switch (anIntroKey)
        {
        case IntroKey_DiceGame:
        {
            std::cout << "A mysterious figure steps forth and reveals a pair of dice.\n";
            std::cout << "\"If you can guess the sum of these when I throw them...\"\n";
            std::cout << "\"I'll reward you handsomely.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        case IntroKey_OddOrEven:
        {
            std::cout << "A mysterious figure steps forth and reveals a pair of dice.\n";
            std::cout << "\"If you can guess if these will roll odd or even\"\n";
            std::cout << "\"I'll reward you handsomely.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        case IntroKey_Blackjack:
        {
            std::cout << "A mysterious figure steps forth and reveals a stack of cards.\n";
            std::cout << "\"Your goal is to get as close to 21 as possible.\"\n";
            std::cout << "\"I'll increase your reward for each card.\"\n";
            std::cout << "\"Go over 21, and your money is mine.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        case IntroKey_RockPaperScissors:
        {
            std::cout << "A mysterious figure steps forth and reveals a hand.\n";
            std::cout << "\"If you can guess what I will throw...\"\n";
            std::cout << "\"I'll reward you handsomely.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        default:
        {
            std::cout << "Key does not exist\n";
            break;
        }
        }
    }
    
    void TotalEarningsMessage(int aTotalEarnings)
    {
        const int winningBig = 1000;
        const int losingBig = 0;

        if (aTotalEarnings >= winningBig)
        {
            std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
            std::cout << "On a roll!\n";
        }
        else if (aTotalEarnings < losingBig)
        {
            std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
            std::cout << "Sadge...\n";
        }
        else
        {
            std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
            std::cout << "Keep gambling!!!\n";
        }
    }

    int GetGameMenu(int aGameNum, int aTotalEarnings, int aPlayerWallet, int aRewardMult)
    {
        const int maxMenu = 3;
        const int minMenu = 1;

        bool menu = true;
        int menuChoice = 0;
        bool startGame = false;

        enum MenuChoice
        {
            MenuChoice_PlayGame = 1,
            MenuChoice_ShowRules = 2,
            MenuChoice_BackToMain = 3
        };
        enum Rules
        {
            Rules_DiceGame = 1,
            Rules_OddOrEven = 2,
            Rules_Blackjack = 3,
            Rules_RockPaperScissor = 4
        };

        while (menu)
        {

            system("cls");
            std::cout << "You have " << aPlayerWallet << "kr \n";
            std::cout << "Reward multiplier: X" << aRewardMult << "\n";
            TotalEarningsMessage(aTotalEarnings);

            std::cout << "\n\nGAME MENU\n";
            std::cout << "1. Play game\n";
            std::cout << "2. Show rules\n";
            std::cout << "3. Back to main menu\n";
            std::cout << "===================================\n\n";

            std::cout << "What will you do? ";
            menuChoice = Player::GetPlayerNum(menuChoice, maxMenu, minMenu);

            switch (menuChoice)
            {
            case MenuChoice_PlayGame:
            {
                startGame = true;
                menu = false;
                break;
            }
            case MenuChoice_ShowRules:
            {
                system("cls");
                std::cout << "RULES:\n";
                if (aGameNum == Rules_DiceGame)
                {
                    std::cout << "1. Guess any number between 2-12\n";
                    std::cout << "2. Two six-sided dice are rolled\n";
                    std::cout << "3. If you guessed the sum, you win\n\n";
                }
                else if (aGameNum == Rules_OddOrEven)
                {
                    std::cout << "1. Place your bet, odd or even\n";
                    std::cout << "2. Two six-sided dice are rolled\n";
                    std::cout << "3. If both sides show odd/even, you win\n";
                    std::cout << "3. Winning multiple times in a row will increase your reward multiplier\n\n\n";
                }
                else if (aGameNum == Rules_Blackjack)
                {
                    std::cout << "1. The deck contains cards with values 1-11.\n";
                    std::cout << "2. Hit to draw a card, stand to end round.\n";
                    std::cout << "3. Each card after your third increases reward.\n";
                    std::cout << "3. If your sum oversteps 21, you lose.\n\n\n";
                }
                else if (aGameNum == Rules_RockPaperScissor)
                {
                    std::cout << "1. Choose rock, paper, or scissors\n";
                    std::cout << "2. The figure will too...\n";
                    std::cout << "3. Rock beats scissors, scissors beats paper, paper beats rock\n\n\n";
                }
                system("pause");
                break;

            }
            case MenuChoice_BackToMain:
            {
                menu = false;
                break;
            }
            default:
            {
                break;
            }
            }
        }
        return startGame;
    }

}