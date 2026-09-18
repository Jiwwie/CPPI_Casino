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
		Blackjack myBlackjack;
		DiceGame myDiceGame;
		OddEven myOddOrEven;
		RPS myRockPaperScissors;
		Roulette myRoulette;
};

