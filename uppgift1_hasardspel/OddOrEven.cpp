#include <iostream>
#include <random>
#include "Shared.h"
#include "Structs.h"
#include "OddOrEven.h"

namespace OddOrEven
{
    void RollDice(Struct::Random& aDie, int aMin, int aMax)
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(aMin, aMax);

        aDie.dieOne = rndDist(rndEngine);
        aDie.dieTwo = rndDist(rndEngine);
    }

    void PlayOddOrEven(Struct::Player& aPlayer, int someStats[], int& someEarnings)
    {
		const int maxGuess = 2;
		const int minGuess = 1;
		const int minBet = 1;
        int playerGuess = 0;
        int rollResult = 0;
        bool oddOrEven = true;
        Struct::Random die = {};

        aPlayer.betMult = 2;

        while (oddOrEven)
        {
            if (!(oddOrEven = Shared::CheckIfBanned(someEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(oddOrEven = Shared::GetGameMenu(3, someEarnings, aPlayer.wallet, aPlayer.betMult)))
            {
                break;
            }

            Shared::ShowGameIntro(Shared::Game_OddOrEven, aPlayer.wallet, aPlayer.betMult);
            Shared::TotalEarningsMessage(someEarnings);

            aPlayer.bet = Shared::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aPlayer.bet == aPlayer.wallet)
            {
                std::cout << "\n***HIGH STAKES***\n";
                std::cout << "Betting your whole wallet fills you with determination.\n";
            }
            std::cout << "_______________________________ \n";


            std::cout << "\nTwo options. What is your bet?\n";
            std::cout << "1. Odd\n";
            std::cout << "2. Even\n";

            playerGuess = Shared::GetPlayerNum(playerGuess, maxGuess, minGuess);
            RollDice(die, 1, 6);

            if (die.dieOne % 2 == 0 && die.dieTwo % 2 == 0)
            {
                rollResult = 2;
            }
            else if (die.dieOne % 2 != 0 && die.dieTwo % 2 != 0)
            {
                rollResult = 1;
            }
            else
            {
                rollResult = 0;
            }

            system("cls");
            std::cout << "\nThe figure throws the dice dramatically...\n\n";

            std::cout << "Die 1: " << die.dieOne;
            if (die.dieOne % 2 == 0)
            {
                std::cout << "  -> Even";
            }
            else
            {
                std::cout << "  -> Odd";
            }

            std::cout << "\nDie 2: " << die.dieTwo;
            if (die.dieTwo % 2 == 0)
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
                std::cout << aPlayer.bet << "X" << aPlayer.betMult << "kr added to wallet.\n";
                std::cout << "Reward multiplier increased by 1.\n";
                Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
                Shared::UpdateStatistics(Shared::GameResult_Win, someStats);
                someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
                aPlayer.betMult += 1;
                std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                system("pause");
                Shared::ShowStatistics(someStats);
            }
            else
            {
                Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
                aPlayer.betMult = 2;

                if (aPlayer.wallet <= 0)
                {
                    std::cout << "\nYou watch as your " << aPlayer.bet << "kr slip away from you...\n";
                    std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                    std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                    system("pause");
                    aPlayer.playing = false;
                    oddOrEven = false;
                    break;
                }
                else
                {
                    std::cout << "\nYou watch as your " << aPlayer.bet << "kr dissappear under the table\n";
                    std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                    Shared::UpdateStatistics(Shared::GameResult_Loss, someStats);
                    someEarnings -= aPlayer.bet;
                    std::cout << "\nYou're having a bad time... Stay determined.\n\n";
                    system("pause");
                    Shared::ShowStatistics(someStats);
                }
            }
        }
    }

}