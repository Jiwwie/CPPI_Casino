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
		void GetMainMenu(Player::PlayerData& player);

	private:
		Misc::Const consts;

		Blackjack myBlackjack;
		DiceGame myDiceGameLow{consts.LOW_STAKES_MIN, consts.LOW_STAKES_MAX};
		DiceGame myDiceGameHigh{consts.HIGH_STAKES_MIN, consts.HIGH_STAKES_MAX};
		OddEven myOddOrEven;
		RPS myRockPaperScissors;
		Roulette myRoulette;

};

