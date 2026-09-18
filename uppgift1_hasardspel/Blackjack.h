#pragma once
#include "Player.h"

class Blackjack
{
	public:
		int DrawCard(int aMin, int aMax);
		void PlayBlackjack(Player::PlayerData& aPlayer, int someStats[]);

	private:
		static int myTotalEarnings;
};
