#pragma once
#include "Player.h"

class OddEven
{
	public:
		void RollDice(Misc::Random& aDie, int aMin, int aMax) const;
		void PlayOddOrEven(Player::PlayerData& aPlayer, int someStats[]);

	private:
		static int myTotalEarnings;
};
