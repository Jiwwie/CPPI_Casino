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

	void InitializeWheel(int aWheel[wheelSize][colSize]);
	void PlayRoulette(Player::Player& aPlayer, int someStats[], int& someEarnings);
}