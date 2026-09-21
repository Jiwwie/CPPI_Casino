#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

int main()
{
	Player::PlayerData player = {};
    Casino casino;

    char readName[17];

    std::cout << "What's your name?\n";
    std::cin.get(readName, 17);

    const char* username = readName;

    system("cls");
    std::cout << "Welcome " << username << '\n';
    system("pause");


    casino.GetMainMenu(player);
}