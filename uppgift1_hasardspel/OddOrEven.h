#pragma once
#include "Player.h"

namespace OddOrEven
{
	void RollDice(Struct::Random& aDie, int aMin, int aMax);
	void PlayOddOrEven(Player::Player& aPlayer, int someStats[], int& someEarnings);
}