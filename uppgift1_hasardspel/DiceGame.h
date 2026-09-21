#pragma once
#include "Player.h"
#include "Misc.h"

class DiceGame
{
	public:
		DiceGame(int aMin, int aMax)
		{
			SetMinBet(aMin);
			SetMaxBet(aMax);
		}

		int GetTotalEarnings();
		void SetMinBet(int aMin);
		void SetMaxBet(int aMax);

		void RollDice(Misc::Random& aDie, int aMin, int aMax);
		void PlayDiceGame(Player::PlayerData& aPlayer, int someStats[]);	

	private:
		static int myTotalEarnings;
		int myMinBet = 0;
		int myMaxBet = 0;
};