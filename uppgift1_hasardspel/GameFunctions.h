#pragma once


namespace GameFunctions
{
    void ShowMainMenuText();
    void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult);
    int GetGameMenu(int aGameNum, int aTotalEarnings, Player::PlayerData& aPlayer);
    void TotalEarningsMessage(int aTotalEarnings);
}