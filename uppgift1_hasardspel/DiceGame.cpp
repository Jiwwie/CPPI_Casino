#include <iostream>
#include <random>
#include "Misc.h"
#include "DiceGame.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

int DiceGame::myTotalEarnings = 0;

int DiceGame::GetTotalEarnings() const
{
    return myTotalEarnings;
}

void DiceGame::SetMinBet(int aMin)
{
    myMinBet = aMin;
}

void DiceGame::SetMaxBet(int aMax)
{
    myMaxBet = aMax;
}

void DiceGame::RollDice(Misc::Random& aDie, int aMin, int aMax) const
{
    std::random_device seed;
    std::mt19937 rndEngine(seed());
    std::uniform_int_distribution<int> rndDist(aMin, aMax);

    aDie.dieOne = rndDist(rndEngine);
    aDie.dieTwo = rndDist(rndEngine);
}


void DiceGame::PlayDiceGame(Player::PlayerData& aPlayer, int someStats[])
{
    bool diceGame = true;
	Misc::Const consts = {};
    Misc::Random die = {};

    while (diceGame)
    {
        if (myFirst == true)
        {
            system("cls");
            std::cout << "1. Guess any number between 2-12\n";
            std::cout << "2. Two six-sided dice are rolled\n";
            std::cout << "3. If you guessed the sum, you win\n\n";
            system("pause");
            system("cls");
            SetMyFirst();
        }

        if (!(diceGame = Player::CheckIfBanned(myTotalEarnings)))
        {
            system("cls");
            std::cout << "\nYou earned too much at this table. Do something else.\n\n";
            system("pause");
            break;
        }
        else if (!(diceGame = GameFunctions::GetGameMenu(Misc::Game_DiceGame, myTotalEarnings, aPlayer)))
        {
            break;
        }

        aPlayer.betMult = consts.DEFAULT_BET_MULT;

        GameFunctions::ShowGameIntro(Misc::Game_DiceGame, aPlayer.wallet, aPlayer.betMult);
        GameFunctions::TotalEarningsMessage(myTotalEarnings);

        if (aPlayer.wallet < myMinBet)
        {
            system("cls");
            std::cout << "\nYou dont have enough kr to play. (minimum " << myMinBet << "kr)\n\n";
            system("pause");
            break;
        }

        std::cout << "\n====================================\n";
        std::cout << "The figure approaches you and opens its hand.\n";
        std::cout << "You have " << aPlayer.wallet << "kr\n";
        std::cout << "You can bet between " << myMinBet << "-" << myMaxBet << "kr. How much will you bet? \n";

        std::cin >> aPlayer.bet;
        while (aPlayer.bet > myMaxBet || aPlayer.bet > aPlayer.wallet || aPlayer.bet < myMinBet || std::cin.fail())
        {
            Player::ClearInputBuffer();
            system("cls");
            if (aPlayer.bet > myMaxBet)
            {
                std::cout << "\nYou can't bet that much. Give a number between " << myMinBet << "-" << myMaxBet << '\n';
            }
            else if (aPlayer.bet < myMinBet)
            {
                std::cout << "\nYou need to bet more. Give a number between " << myMinBet << "-" << myMaxBet << '\n';
            }
            else
            {
                std::cout << "\nGive a number between " << myMinBet << "-" << myMaxBet << '\n';
            }
            std::cout << "You have " << aPlayer.wallet << "kr. What is your bet?\n";
            std::cin >> aPlayer.bet;
        }
        Player::ClearInputBuffer();

        system("cls");
        std::cout << "\nThe figure accepts your offer. \n";
        if (aPlayer.bet == aPlayer.wallet)
        {
            std::cout << "\n***HIGH STAKES***\n";
            std::cout << "Betting your whole wallet increases your reward multiplier to X3.\n";
            aPlayer.betMult = consts.HIGH_STAKES_MULT;
        }
        std::cout << "_______________________________ \n";
        std::cout << "What is your guess? (" << consts.DICE_MIN_GUESS << "-" << consts.DICE_MAX_GUESS << ")  ";
        aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.DICE_MAX_GUESS, consts.DICE_MIN_GUESS);
        RollDice(die, consts.DICE_MIN_VAL, consts.DICE_MAX_VAL);

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
            Player::UpdatePlayerWallet(aPlayer, '+');
            Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
            myTotalEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
            std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
            std::cout << "You are filled with determination.\n\n";
            system("pause");
            Statistics::ShowStatistics(someStats);
        }
        else
        {
            Player::UpdatePlayerWallet(aPlayer, '-');
            std::cout << "\nYou watch as your " << aPlayer.bet << "kr disappear under the table\n";
            std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
            myTotalEarnings -= aPlayer.bet;

            if (aPlayer.wallet <= 0)
            {
                std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino.\n";
                std::cout << Player::GetUsername() << "! Stay determined! The casino will let you back in next CSN.\n\n\n";
                system("pause");
                aPlayer.playing = false;
                diceGame = false;
                break;
            }
            else
            {
                std::cout << "\nYou're having a bad time... " << Player::GetUsername() << "! Stay determined.\n\n\n";
                Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
                system("pause");
                Statistics::ShowStatistics(someStats);
            }
        }
    }
}
