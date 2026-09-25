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

		int GetTotalEarnings() const;
		void SetMinBet(int aMin);
		void SetMaxBet(int aMax);

		void RollDice(Misc::Random& aDie, int aMin, int aMax) const;
		void PlayDiceGame(Player::PlayerData& aPlayer, int someStats[]);	

		void SetMyFirst() { myFirst = false; }

	private:
		static int myTotalEarnings;
		bool myFirst = true;
		int myMinBet = 0;
		int myMaxBet = 0;
};