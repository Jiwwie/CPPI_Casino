#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

int main()
{
	Player::PlayerData player = {};
    Casino casino;

    bool validName = false;
    int nameLength = 0;
    char readName[17] = {0};

    for (int i = 0; i < sizeof(readName); i++)
    {
        if (readName[i] == '\0')
        {
            nameLength = i;
        }
    }

    do
    {
        validName = false;
        system("cls");
        Player::ClearInputBuffer();
        std::cout << "Enter your name: ";
        std::cin.get(readName, 17);

        for (int i = 0; i < nameLength; i++)
        {
            if (readName[i] == '\0' && i < 2)
            {
                std::cout << "name too short" << '\n';
                break;
            }
            else if (readName[i] == '\0')
            {
                validName = true;
            }

            if (readName[i] != '\0' && i == 16)
            {
                std::cout << "name too long" << '\n';
                break;
            }

            if ((readName[i] > 'z' || readName[i] < 'A') && readName[i] != '\0')
            {
                validName = false;
                std::cout << "invalid character." << '\n';
                break;
            }
        }

        system("pause");

    } while (!validName);

    const char* username = readName;

    system("cls");
    std::cout << "Welcome " << username << '\n';
    system("pause");


    casino.GetMainMenu(player);
}