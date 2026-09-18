#pragma once
#include "Player.h"
#include "Misc.h"

class RPS
{
	public:
		void RollRPS(Misc::Random& aRPS, int aMin, int aMax);
		void PlayRPS(Player::PlayerData& aPlayer, int someStats[], int& someEarnings);

	private:

};
