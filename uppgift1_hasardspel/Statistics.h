#pragma once

namespace Statistics
{
    enum GameResult
    {
        GameResult_NoStat = 0,
        GameResult_Win = 1,
        GameResult_Loss = 2,
    };

    void WriteStat(int aPlace, int someStats[]);
    void UpdateStatistics(int aStat, int someStats[]);
    void ShowStatistics(int someStats[]);
}