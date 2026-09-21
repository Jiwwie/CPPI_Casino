#pragma once

namespace Player
{
	struct PlayerData
	{
		int input = -1;

		int wallet = 1000;
		int bet = -1;
		int betMult = 2;
		
		bool playing = true;
		bool banned = false;
	};

    void ClearInputBuffer();
    int GetPlayerNum(int aPlayerNum, int aMax, int aMin);
	void GetPlayerBet(Player::PlayerData& aPlayer, int aMax, int aMin);
    int CheckIfBanned(int aTotalEarnings);
    void UpdatePlayerWallet(Player::PlayerData& aPlayer, char anOperator);
}