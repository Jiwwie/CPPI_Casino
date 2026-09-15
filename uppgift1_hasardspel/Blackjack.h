#pragma once
#include "Player.h"

namespace Blackjack
{
	int DrawCard(int aMin, int aMax);
	void PlayBlackjack(Player::Player& aPlayer, int someStats[], int& someEarnings);
}