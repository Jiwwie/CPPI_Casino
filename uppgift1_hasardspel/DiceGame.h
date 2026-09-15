#pragma once
#include "Player.h"
#include "Structs.h"

namespace DiceGame
{
	void RollDice(Struct::Random& aDie, int aMin, int aMax);
	void PlayDiceGame(Player::Player& aPlayer, int someStats[], int& someEarnings);
}