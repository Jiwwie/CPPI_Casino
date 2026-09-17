#pragma once

namespace Misc
{

	enum Game
	{
		Game_DiceGame = 1,
		Game_OddOrEven = 2,
		Game_Blackjack = 3,
		Game_RockPaperScissors = 4,
		Game_Roulette = 5
	};

	struct Random
	{
		int dieOne;
		int dieTwo;
		int rps;
		int ball;
	};

	struct Const
	{
		const int MIN_BET = 1;
		const int DEFAULT_BET_MULT = 2;
		const int HIGH_STAKES_MULT = 3;
		const int STRAIGHT_MULT = 30;

		const int DICE_MIN_GUESS = 2;
		const int DICE_MAX_GUESS = 12;
		const int DICE_MIN_VAL = 1;
		const int DICE_MAX_VAL = 6;

		const int ODDEVEN_MIN_INPUT = 1;
		const int ODDEVEN_MAX_INPUT = 2;

		const int BLACKJACK_MIN_VAL = 1;
		const int BLACKJACK_MAX_VAL = 11;
		const int BLACKJACK_MIN_COUNT = 3;

		const int RPS_MIN_INPUT = 1;
		const int RPS_MAX_INPUT = 3;

		const int ROULETTE_MAX_NUM = 36;
		const int ROULETTE_MIN_NUM = 0;
		const int ROULETTE_COL_DISTANCE = 3;
		const int ROULETTE_MIN_MENU = 1;
		const int ROULETTE_MAX_MENU = 4;
		const int ROULETTE_MIN_TWO_OPT = 1;
		const int ROULETTE_MAX_TWO_OPT = 2;
		const int ROULETTE_MIN_COL = 1;
		const int ROULETTE_MAX_COL = 3;
	};
}