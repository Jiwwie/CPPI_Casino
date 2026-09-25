#pragma once
#include "Player.h"
#include "Misc.h"

class RPS
{
	public:
		void RollRPS(Misc::Random& aRPS, int aMin, int aMax) const;
		void PlayRPS(Player::PlayerData& aPlayer, int someStats[]);

		void SetMyFirst() { myFirst = false; }

	private:
		static int myTotalEarnings;
		bool myFirst = true;
};
