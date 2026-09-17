#pragma once

namespace Player
{
	struct PlayerData
	{
		int input;

		int wallet = 1000;
		int bet;
		int betMult = 2;
		
		bool playing = true;
		bool banned = false;
	};

	struct TotalEarnings
	{
		int DiceGame;
		int OddOrEven;
		int Blackjack;
		int RockPaperScissors;
		int Roulette;
	};

    void ClearInputBuffer();
    int GetPlayerNum(int aPlayerNum, int aMax, int aMin);
    int GetPlayerBet(int aPlayerNum, int aMax, int aMin);
    int CheckIfBanned(int aTotalEarnings);
    void UpdatePlayerWallet(Player::PlayerData& aPlayer, char anOperator);
}