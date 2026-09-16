#pragma once
#include "Player.h"

namespace Roulette
{
	const int wheelSize = 37;
	const int colSize = 2;

	enum Color
	{
		Color_Green = 0,
		Color_Red = 1,
		Color_Black = 2,
	};

	enum BettingOption
	{
		BettingOption_Straight = 1,
		BettingOption_OddEven = 2,
		BettingOption_RedBlack = 3,
		BettingOption_Column = 4
	};

	void InitializeWheel(int aWheel[wheelSize][colSize]);
	void GetColumn(int aWheel[wheelSize][colSize], int aColumn);
	void PlayRoulette(Player::Player& aPlayer, int someStats[], int& someEarnings);
}