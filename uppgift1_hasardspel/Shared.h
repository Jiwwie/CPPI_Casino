#pragma once


struct Dice
{
    int one;
    int two;
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