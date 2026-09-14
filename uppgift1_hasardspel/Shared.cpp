#include <iostream>
#include <random>
#include "Shared.h"

namespace SharedFunctions
{
    void ShowMainMenu()
    {
        system("cls");
        std::cout << " =======================\n";
        std::cout << "||       CASINO        ||\n";
        std::cout << " =======================\n\n";

        std::cout << "\"It's a beautiful day outside,\n";
        std::cout << " Birds are singing,\n";
        std::cout << " Flowers are blooming...\n";
        std::cout << " On days like these,\n";
        std::cout << " Kids like you should be spending your CSN\"\n\n";

        std::cout << "What do you want to do? (1-5) " << std::endl;
        std::cout << "1. Dice Game" << std::endl;
        std::cout << "2. Odd or Even" << std::endl;
        std::cout << "3. Blackjack (lite)" << std::endl;
        std::cout << "4. Show statistics" << std::endl;
        std::cout << "5. Leave Casino\n" << std::endl;
    }

    void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult)
    {
        enum IntroKey
        {
            IntroKey_DiceGame = 1,
            IntroKey_OddOrEven = 2,
            IntroKey_Blackjack = 3
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
        default:
        {
            std::cout << "Key does not exist\n";
            break;
        }
        }
    }

    void ClearInputBuffer()
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    void UpdatePlayerWallet(int aBetAmount, int aMultiplier, char anOperator, int& aPlayerWallet)
    {
        switch (anOperator)
        {
        case '+':
        {
            aPlayerWallet = (aPlayerWallet + (aBetAmount * aMultiplier)) - aBetAmount;
            break;
        }
        case '-':
        {
            aPlayerWallet = aPlayerWallet - aBetAmount;
            break;
        }
        default:
            break;
        }
    }

    void UpdateStatistics(int aStat, int someStats[])
    {
        const int statSize = 5;

        for (int i = (statSize - 1); i > 0; i--)
        {
            someStats[i] = someStats[i - 1];
        }
        someStats[0] = aStat;
    }

    int GetPlayerNum(int aPlayerNum, int aMax, int aMin)
    {
        std::cin >> aPlayerNum;
        while (aPlayerNum > aMax || aPlayerNum < aMin || std::cin.fail())
        {
            ClearInputBuffer();
            std::cout << "\nInvalid option. ";
            std::cin >> aPlayerNum;
        }
        ClearInputBuffer();
        return aPlayerNum;
    }

    int GetPlayerBet(int aPlayerNum, int aMax, int aMin)
    {
        std::cout << "\n====================================\n";
        std::cout << "The figure approaches you and opens its hand.\n";
        std::cout << "How much will you bet? \n";

        std::cin >> aPlayerNum;

        while (aPlayerNum > aMax || aPlayerNum < aMin || std::cin.fail())
        {
            if (aPlayerNum > aMax)
            {
                ClearInputBuffer();
                std::cout << "\nYou don't have that much... \n";
                std::cout << "What is your bet? \n";
                std::cin >> aPlayerNum;
            }
            else if (aPlayerNum < aMin)
            {
                ClearInputBuffer();
                std::cout << "\nAre you trying to rip me off? \n";
                std::cout << "What is your bet? \n";
                std::cin >> aPlayerNum;
            }
            else
            {
                ClearInputBuffer();
                std::cout << "\nInvalid option. ";
                std::cin >> aPlayerNum;
            }
        }
        ClearInputBuffer();
        return aPlayerNum;
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
            Rules_Blackjack = 3
        };

        while (menu)
        {

            system("cls");
            std::cout << "You have " << aPlayerWallet << "kr \n";
            std::cout << "Reward multiplier: X" << aRewardMult << "\n";
            SharedFunctions::TotalEarningsMessage(aTotalEarnings);

            std::cout << "\n\nGAME MENU\n";
            std::cout << "1. Play game\n";
            std::cout << "2. Show rules\n";
            std::cout << "3. Back to main menu\n";
            std::cout << "===================================\n\n";

            std::cout << "What will you do? ";
            menuChoice = SharedFunctions::GetPlayerNum(menuChoice, maxMenu, minMenu);

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

    int CheckIfBanned(int aTotalEarnings)
    {
        const int maxEarnings = 5000;

        if (aTotalEarnings >= maxEarnings)
        {
            return false;
        }
        else
        {
            return true;
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

    void WriteStat(int aPlace, int someStats[])
    {
        enum Stat
        {
            Stat_NoStat = 0,
            Stat_Win = 1,
            Stat_Loss = 2
        };

        if (someStats[aPlace] == Stat_NoStat)
        {
            std::cout << aPlace + 1 << ". " << "No stat" << std::endl;
        }
        else if (someStats[aPlace] == Stat_Win)
        {
            std::cout << aPlace + 1 << ". " << "Win" << std::endl;
        }
        else if (someStats[aPlace] == Stat_Loss)
        {
            std::cout << aPlace + 1 << ". " << "Loss" << std::endl;
        }
    }

    void ShowStatistics(int someStats[])
    {
        system("cls");
        std::cout << "======================" << std::endl;
        std::cout << "Recent game logs:" << std::endl;
        WriteStat(0, someStats);
        WriteStat(1, someStats);
        WriteStat(2, someStats);
        WriteStat(3, someStats);
        WriteStat(4, someStats);
        std::cout << "======================" << std::endl;
        std::cout << "\n\n";
        system("pause");
    }

    void RollDice(Dice& aDie)
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(1, 6);

        aDie.one = rndDist(rndEngine);
        aDie.two = rndDist(rndEngine);
    }

    int DrawCard()
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(1, 11);
        return rndDist(rndEngine);
    }
}


