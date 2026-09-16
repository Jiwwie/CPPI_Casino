#include <iostream>
#include <random>
#include "Misc.h"
#include "DiceGame.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

namespace DiceGame
{
    void RollDice(Misc::Random& aDie, int aMin, int aMax)
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(aMin, aMax);

        aDie.dieOne = rndDist(rndEngine);
        aDie.dieTwo = rndDist(rndEngine);
    }

    void PlayDiceGame(Player::Player& aPlayer, int someStats[], int& someEarnings)
    {
		const int maxGuess = 12;
		const int minGuess = 2;
		const int minBet = 1;
        bool diceGame = true;
        Misc::Random die = {};

        while (diceGame)
        {
            if (!(diceGame = Player::CheckIfBanned(someEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(diceGame = GameFunctions::GetGameMenu(3, someEarnings, aPlayer.wallet, aPlayer.betMult)))
            {
                break;
            }

            aPlayer.betMult = 2;

            GameFunctions::ShowGameIntro(Misc::Game_DiceGame, aPlayer.wallet, aPlayer.betMult);
            GameFunctions::TotalEarningsMessage(someEarnings);

            aPlayer.bet = Player::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aPlayer.bet == aPlayer.wallet)
            {
                std::cout << "\n***HIGH STAKES***\n";
                std::cout << "Betting your whole wallet increases your reward multiplier to X3.\n";
                aPlayer.betMult = 3;
            }
            std::cout << "_______________________________ \n";
            std::cout << "What is your guess? (2-12)  ";
            aPlayer.input = Player::GetPlayerNum(aPlayer.input, maxGuess, minGuess);
            RollDice(die, 1, 6);

            system("cls");
            std::cout << "\nThe figure throws the dice dramatically...\n\n";
            std::cout << "Die 1: " << die.dieOne << std::endl;
            std::cout << "Die 2: " << die.dieTwo << std::endl;
            std::cout << "Sum: " << die.dieOne + die.dieTwo << std::endl;
            std::cout << "Your guess: " << aPlayer.input << std::endl;

            if (aPlayer.input == die.dieOne + die.dieTwo)
            {
                std::cout << "\nThe figure winks and slips you something under the table.\n";
                std::cout << aPlayer.bet << "X" << aPlayer.betMult << "kr added to wallet.\n";
                Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
                Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
                someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
                std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                std::cout << "You are filled with determination.\n\n";
                system("pause");
                Statistics::ShowStatistics(someStats);
            }
            else
            {
                Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
                std::cout << "\nYou watch as your " << aPlayer.bet << "kr dissappear under the table\n";
                std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                someEarnings -= aPlayer.bet;

                if (aPlayer.wallet <= 0)
                {
                    std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                    system("pause");
                    aPlayer.playing = false;
                    diceGame = false;
                    break;
                }
                else
                {
                    std::cout << "\nYou're having a bad time... Stay determined.\n\n\n";
                    Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
                    system("pause");
                    Statistics::ShowStatistics(someStats);
                }
            }
        }
    }
}