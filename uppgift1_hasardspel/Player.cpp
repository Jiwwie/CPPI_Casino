#include <iostream>
#include "Player.h"

namespace Player
{
    void ClearInputBuffer()
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    void UpdatePlayerWallet(Player::PlayerData& aPlayer, char anOperator)
    {
        switch (anOperator)
        {
        case '+':
        {
            aPlayer.wallet = (aPlayer.wallet + (aPlayer.bet * aPlayer.betMult)) - aPlayer.bet;
            break;
        }
        case '-':
        {
            aPlayer.wallet = aPlayer.wallet - aPlayer.bet;
            break;
        }
        default:
            break;
        }
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
    
    void GetPlayerBet(Player::PlayerData& aPlayer, int aMax, int aMin)
    {
        std::cout << "\n====================================\n";
        std::cout << "The figure approaches you and opens its hand.\n";
        std::cout << "You have "  << aPlayer.wallet << "kr. How much will you bet? \n";

        std::cin >> aPlayer.bet;

        while (aPlayer.bet > aMax || aPlayer.bet < aMin || std::cin.fail())
        {
            ClearInputBuffer();
            if (aPlayer.bet > aMax)
            {
                std::cout << "\nYou don't have that much... \n";
                std::cout << "What is your bet? \n";
                std::cin >> aPlayer.bet;
            }
            else if (aPlayer.bet < aMin)
            {
                std::cout << "\nAre you trying to rip me off? \n";
                std::cout << "What is your bet? \n";
                std::cin >> aPlayer.bet;
            }
            else
            {
                std::cout << "\nInvalid option. ";
                std::cin >> aPlayer.bet;
            }
        }
        ClearInputBuffer();
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

}