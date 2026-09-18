#pragma once
#include "Player.h"

class OddEven
{
public:
	void RollDice(Misc::Random& aDie, int aMin, int aMax);
	void PlayOddOrEven(Player::PlayerData& aPlayer, int someStats[], int& someEarnings);

private:

};
