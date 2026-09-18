#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Casino.h"

int main()
{
	Player::PlayerData player = {};
    Casino casino;
    
    casino.GetMainMenu(player);

}