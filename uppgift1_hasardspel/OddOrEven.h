#pragma once
#include "Player.h"

namespace OddOrEven
{
	void RollDice(Misc::Random& aDie, int aMin, int aMax);
	void PlayOddOrEven(Player::Player& aPlayer, int someStats[], int& someEarnings);
}