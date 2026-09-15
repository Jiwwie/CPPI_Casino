#pragma once

struct Dice
{
    int one;
    int two;
};

struct TotalEarnings
{
	int DiceGame;
	int OddOrEven;
	int Blackjack;
	int RockPaperScissors;
};

enum GameResult
{
	GameResult_NoStat = 0,
	GameResult_Win = 1,
	GameResult_Loss = 2
};

enum Game
{
	Game_DiceGame = 1,
	Game_OddOrEven = 2,
	Game_Blackjack = 3,
	Game_RockPaperScissors = 4
};

namespace SharedFunctions
{
    void ShowMainMenu();
    void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult);
    int GetGameMenu(int aGameNum, int aTotalEarnings, int aPlayerWallet, int aRewardMult);
    void TotalEarningsMessage(int aTotalEarnings);
    void ClearInputBuffer();
    int GetPlayerNum(int aPlayerNum, int aMax, int aMin);
    int GetPlayerBet(int aPlayerNum, int aMax, int aMin);
    void UpdatePlayerWallet(int aBetAmount, int aMultiplier, char anOperator, int& aPlayerWallet);
    int CheckIfBanned(int aTotalEarnings);
    void UpdateStatistics(int aStat, int someStats[]);
    void WriteStat(int aPlace, int someStats[]);
    void ShowStatistics(int someStats[]);

    void RollDice(Dice& aDie);
    int DrawCard();

}