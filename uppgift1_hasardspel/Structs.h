#pragma once

namespace Struct
{
	struct Player
	{
		int input;
		int wallet = 1000;
		int bet;
		int betMult = 2;
		bool playing = true;
		bool banned = false;
	};

	struct Random
	{
		int dieOne;
		int dieTwo;
		int rps;
	};

	struct TotalEarnings
	{
		int DiceGame;
		int OddOrEven;
		int Blackjack;
		int RockPaperScissors;
	};
}