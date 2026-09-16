#pragma once
#include "Player.h"

namespace Blackjack
{
	int DrawCard(int aMin, int aMax);
	void PlayBlackjack(Player::PlayerData& aPlayer, int someStats[], int& someEarnings);
}