#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

int main()
{
	Player::PlayerData player = {};
    Casino casino;

    Player::GetUsername();

    system("cls");
    std::cout << "Welcome " << Player::GetUsername() << '\n';
    system("pause");


    casino.GetMainMenu(player);
}

