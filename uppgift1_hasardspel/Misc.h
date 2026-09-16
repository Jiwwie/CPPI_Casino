#pragma once

namespace Misc
{
	struct Random
	{
		int dieOne;
		int dieTwo;
		int rps;
		int ball;
	};

	enum Game
	{
		Game_DiceGame = 1,
		Game_OddOrEven = 2,
		Game_Blackjack = 3,
		Game_RockPaperScissors = 4,
		Game_Roulette = 5
	};
}