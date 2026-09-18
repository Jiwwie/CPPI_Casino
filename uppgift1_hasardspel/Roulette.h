#pragma once
#include "Player.h"

const int wheelSize = 37;
const int colSize = 2;

	class Roulette
	{
		public:
			void InitializeWheel(int aWheel[wheelSize][colSize]);
			void GetColumn(int aWheel[wheelSize][colSize], int aColumn);
			void SpinBall(Misc::Random& aBall, int aMin, int aMax);
			void PlayRoulette(Player::PlayerData& aPlayer, int someStats[]);


		private:
			static int myTotalEarnings;

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

	};
