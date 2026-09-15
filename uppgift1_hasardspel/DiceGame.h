#pragma once

namespace DiceGame
{
	void RollDice(Struct::Random& aDie, int aMin, int aMax);
	void PlayDiceGame(Struct::Player& aPlayer, int someStats[], int& someEarnings);
}