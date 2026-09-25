#pragma once
#include <iostream>
#include <cstdlib>
#include <random>
#include "DiceGame.h"
#include "OddOrEven.h"
#include "Blackjack.h"
#include "RockPaperScissors.h"
#include "Roulette.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

class Casino
{
	public:
		void GetMainMenu(Player::PlayerData& aPlayer);

	private:
		Misc::Const myConsts;

		Blackjack myBlackjack;
		DiceGame myDiceGameLow{myConsts.LOW_STAKES_MIN, myConsts.LOW_STAKES_MAX};
		DiceGame myDiceGameHigh{myConsts.HIGH_STAKES_MIN, myConsts.HIGH_STAKES_MAX};
		OddEven myOddOrEven;
		RPS myRockPaperScissors;
		Roulette myRoulette;

};

