#pragma once
#include "Player.h"
#include "Misc.h"

class DiceGame
{
	public:
		void RollDice(Misc::Random& aDie, int aMin, int aMax);
		void PlayDiceGame(Player::PlayerData& aPlayer, int someStats[]);	

		int getTotalEarnings()
		{
			return myTotalEarnings;
		}

	private:
		static int myTotalEarnings;
};