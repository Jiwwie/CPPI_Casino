#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

const char* GetUsername();

int main()
{
	Player::PlayerData player = {};
    Casino casino;

    GetUsername();

    system("cls");
    std::cout << "Welcome " << GetUsername() << '\n';
    system("pause");


    casino.GetMainMenu(player);
}

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
                std::cout << "name too short" << '\n';
                validName = false;
                break;
            }
            else if (readName[i] == '\0' && i >= arrayLength - 1)
            {
                std::cout << "name too long" << '\n';
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
                    std::cout << "invalid character." << '\n';
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