#include <iostream>
#include "Player.h"

namespace Player
{
    const char* GetUsername()
    {
        static bool validName = false;
        const int arrayLength = 18;

        static char readName[arrayLength] = { 0 }; 
        int nameLength = 0;

        while (!validName)
        {
            validName = true;
            system("cls");
            std::cout << "Enter your name: ";
            std::cin.get(readName, arrayLength);

            for (int i = 0; i < arrayLength; i++)
            {
                if (readName[i] == '\0' && i < 2)
                {
                    std::cout << "Name too short." << '\n';
                    validName = false;
                    break;
                }
                else if (readName[i] == '\0' && i >= arrayLength - 1)
                {
                    std::cout << "Name too long." << '\n';
                    validName = false;
                    break;
                }

                if (readName[i] == '\0')
                {
                    nameLength = i;
                    //std::cout << nameLength << '\n';
                    break;
                }
            }

            for (int i = 0; i < nameLength; i++)
            {
                if ((readName[i] > 'z' || readName[i] < 'a') && readName[i] != '\0')
                {
                    if ((readName[i] > 'Z' || readName[i] < 'A'))
                    {
                        std::cout << "Only use letters." << '\n';
                        validName = false;
                        break;
                    }
                }
            }

            if (validName == true)
            {
                std::cout << "Username accepted. " << '\n';
            }

            system("pause");
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        return readName;
    }

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