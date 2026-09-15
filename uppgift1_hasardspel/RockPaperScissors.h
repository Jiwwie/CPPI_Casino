#pragma once

namespace RockPaperScissors
{
	void RollRPS(Struct::Random& aRPS, int aMin, int aMax);
	void PlayRPS(Struct::Player& aPlayer, int someStats[], int& someEarnings);
}