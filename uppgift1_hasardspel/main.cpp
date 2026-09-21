#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

int main()
{
	Player::PlayerData player = {};
    Casino casino;

    bool validName = false;
    char readName[17];

    do
    {
        std::cout << "Enter your name: ";
        std::cin.get(readName, 17);
        std::cout << sizeof(readName) << '\n';
        system("pause");

    } while (validName);

    const char* username = readName;

    system("cls");
    std::cout << "Welcome " << username << '\n';
    system("pause");


    casino.GetMainMenu(player);
}