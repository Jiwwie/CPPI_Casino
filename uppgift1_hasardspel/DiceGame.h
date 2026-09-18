#pragma once
#include "Player.h"
#include "Misc.h"

class DiceGame
{
	public:
		/*
		DiceGame(int aMin, int aMax) 
		{
			SetMinBet(aMin);
			SetMinBet(aMax);
		}
		*/

		void RollDice(Misc::Random& aDie, int aMin, int aMax);
		void PlayDiceGame(Player::PlayerData& aPlayer, int someStats[]);	

		int GetTotalEarnings()
		{
			return myTotalEarnings;
		}

		void SetMinBet(int aMin)
		{
			myMinBet = aMin;
		}

		void SetMaxBet(int aMax)
		{
			myMaxBet = aMax;
		}

	private:
		static int myTotalEarnings;
		int myMinBet = 0;
		int myMaxBet = 1000;
};