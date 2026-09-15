#pragma once

namespace Blackjack
{
	int DrawCard(int aMin, int aMax);
	void PlayBlackjack(Struct::Player& aPlayer, int someStats[], int& someEarnings);
}