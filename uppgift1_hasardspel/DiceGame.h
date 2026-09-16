#pragma once
#include "Player.h"
#include "Misc.h"

namespace DiceGame
{
	void RollDice(Misc::Random& aDie, int aMin, int aMax);
	void PlayDiceGame(Player::PlayerData& aPlayer, int someStats[], int& someEarnings);
}