#include <iostream>
#include <random>
#include "Shared.h"
#include "OddOrEven.h"

namespace OddOrEven
{
    void PlayOddOrEven(bool& gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[])
    {
		const int maxGuess = 2;
		const int minGuess = 1;
		const int minBet = 1;
        int playerGuess = 0;
        int rollResult = 0;
        static signed int totalEarnings = 0;
        bool oddOrEven = true;
        Dice die = {};

        aRewardMult = 2;

        while (oddOrEven)
        {
            if (!(oddOrEven = SharedFunctions::CheckIfBanned(totalEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(oddOrEven = SharedFunctions::GetGameMenu(3, totalEarnings, aPlayerWallet, aRewardMult)))
            {
                break;
            }

            SharedFunctions::ShowGameIntro(Game_OddOrEven, aPlayerWallet, aRewardMult);
            SharedFunctions::TotalEarningsMessage(totalEarnings);

            aBetAmount = SharedFunctions::GetPlayerBet(aBetAmount, aPlayerWallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aBetAmount == aPlayerWallet)
            {
                std::cout << "\n***HIGH STAKES***\n";
                std::cout << "Betting your whole wallet fills you with determination.\n";
            }
            std::cout << "_______________________________ \n";


            std::cout << "\nTwo options. What is your bet?\n";
            std::cout << "1. Odd\n";
            std::cout << "2. Even\n";

            playerGuess = SharedFunctions::GetPlayerNum(playerGuess, maxGuess, minGuess);
            SharedFunctions::RollDice(die);

            if (die.one % 2 == 0 && die.two % 2 == 0)
            {
                rollResult = 2;
            }
            else if (die.one % 2 != 0 && die.two % 2 != 0)
            {
                rollResult = 1;
            }
            else
            {
                rollResult = 0;
            }

            system("cls");
            std::cout << "\nThe figure throws the dice dramatically...\n\n";

            std::cout << "Die 1: " << die.one;
            if (die.one % 2 == 0)
            {
                std::cout << "  -> Even";
            }
            else
            {
                std::cout << "  -> Odd";
            }

            std::cout << "\nDie 2: " << die.two;
            if (die.two % 2 == 0)
            {
                std::cout << "  -> Even";
            }
            else
            {
                std::cout << "  -> Odd";
            }

            std::cout << "\n\nYou guessed: ";
            if (playerGuess == 1)
            {
                std::cout << "Odd\n";
            }
            else
            {
                std::cout << "Even\n";
            }

            if (playerGuess == rollResult)
            {
                std::cout << "The figure nods slowly while handing over your reward.\n\n";
                std::cout << aBetAmount << "X" << aRewardMult << "kr added to wallet.\n";
                std::cout << "Reward multiplier increased by 1.\n";
                SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
                SharedFunctions::UpdateStatistics(GameResult_Win, someStats);
                totalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
                aRewardMult += 1;
                std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                system("pause");
                SharedFunctions::ShowStatistics(someStats);
            }
            else
            {
                SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
                aRewardMult = 2;

                if (aPlayerWallet <= 0)
                {
                    std::cout << "\nYou watch as your " << aBetAmount << "kr slip away from you...\n";
                    std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                    std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                    system("pause");
                    gameRunning = false;
                    oddOrEven = false;
                    break;
                }
                else
                {
                    std::cout << "\nYou watch as your " << aBetAmount << "kr dissappear under the table\n";
                    std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                    SharedFunctions::UpdateStatistics(GameResult_Loss, someStats);
                    totalEarnings -= aBetAmount;
                    std::cout << "\nYou're having a bad time... Stay determined.\n\n";
                    system("pause");
                    SharedFunctions::ShowStatistics(someStats);
                }
            }
        }
    }

}