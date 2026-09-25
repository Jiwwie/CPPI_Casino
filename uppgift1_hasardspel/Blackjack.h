#pragma once
#include "Player.h"

class Blackjack
{
	public:
		int DrawCard(int aMin, int aMax) const;
		void PlayBlackjack(Player::PlayerData& aPlayer, int someStats[]);

		void SetMyFirst() { myFirst = false; }

	private:
		static int myTotalEarnings;
		bool myFirst = true;
};
