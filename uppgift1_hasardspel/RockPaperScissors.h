#pragma once
#include "Player.h"
#include "Structs.h"

namespace RockPaperScissors
{
	void RollRPS(Struct::Random& aRPS, int aMin, int aMax);
	void PlayRPS(Player::Player& aPlayer, int someStats[], int& someEarnings);
}