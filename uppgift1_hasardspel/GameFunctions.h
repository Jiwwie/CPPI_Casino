#pragma once


namespace GameFunctions
{
    void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult);
    int GetGameMenu(int aGameNum, int aTotalEarnings, int aPlayerWallet, int aRewardMult);
    void TotalEarningsMessage(int aTotalEarnings);
}