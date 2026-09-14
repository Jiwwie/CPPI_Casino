#include <iostream>
#include <random>
#include "Shared.h"
#include "DiceGame.h"

namespace DiceGame
{
    void PlayDiceGame(bool gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[], int& someTotalEarnings)
    {
		const int maxGuess = 12;
		const int minGuess = 2;
		const int minBet = 1;
        int playerGuess = 0;
        bool diceGame = true;
        Dice die = {};

        while (diceGame)
        {
            if (!(diceGame = SharedFunctions::CheckIfBanned(someTotalEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(diceGame = SharedFunctions::GetGameMenu(3, someTotalEarnings, aPlayerWallet, aRewardMult)))
            {
                break;
            }

            aRewardMult = 2;

            SharedFunctions::ShowGameIntro(Game_DiceGame, aPlayerWallet, aRewardMult);
            SharedFunctions::TotalEarningsMessage(someTotalEarnings);

            aBetAmount = SharedFunctions::GetPlayerBet(aBetAmount, aPlayerWallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aBetAmount == aPlayerWallet)
            {
                std::cout << "\n***HIGH STAKES***\n";
                std::cout << "Betting your whole wallet increases your reward multiplier to X3.\n";
                aRewardMult = 3;
            }
            std::cout << "_______________________________ \n";
            std::cout << "What is your guess? (2-12)  ";
            playerGuess = SharedFunctions::GetPlayerNum(playerGuess, maxGuess, minGuess);
            SharedFunctions::RollDice(die);

            system("cls");
            std::cout << "\nThe figure throws the dice dramatically...\n\n";
            std::cout << "Die 1: " << die.one << std::endl;
            std::cout << "Die 2: " << die.two << std::endl;
            std::cout << "Sum: " << die.one + die.two << std::endl;
            std::cout << "Your guess: " << playerGuess << std::endl;

            if (playerGuess == die.one + die.two)
            {
                std::cout << "\nThe figure winks and slips you something under the table.\n";
                std::cout << aBetAmount << "X" << aRewardMult << "kr added to wallet.\n";
                SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
                SharedFunctions::UpdateStatistics(GameResult_Win, someStats);
                someTotalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
                std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                std::cout << "You are filled with determination.\n\n";
                system("pause");
                SharedFunctions::ShowStatistics(someStats);
            }
            else
            {
                SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
                std::cout << "\nYou watch as your " << aBetAmount << "kr dissappear under the table\n";
                std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                someTotalEarnings -= aBetAmount;

                if (aPlayerWallet <= 0)
                {
                    std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                    system("pause");
                    gameRunning = false;
                    diceGame = false;
                    break;
                }
                else
                {
                    std::cout << "\nYou're having a bad time... Stay determined.\n\n\n";
                    SharedFunctions::UpdateStatistics(GameResult_Loss, someStats);
                    system("pause");
                    SharedFunctions::ShowStatistics(someStats);
                }
            }
        }
    }
}