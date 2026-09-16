#pragma once
#include "Player.h"
#include "Misc.h"

namespace RockPaperScissors
{
	void RollRPS(Misc::Random& aRPS, int aMin, int aMax);
	void PlayRPS(Player::PlayerData& aPlayer, int someStats[], int& someEarnings);
}