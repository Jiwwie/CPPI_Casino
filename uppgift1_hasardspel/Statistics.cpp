#include <iostream>

namespace Statistics
{
    void UpdateStatistics(int aStat, int someStats[])
    {
        const int statSize = 5;

        for (int i = (statSize - 1); i > 0; i--)
        {
            someStats[i] = someStats[i - 1];
        }
        someStats[0] = aStat;
    }

    void WriteStat(int aPlace, int someStats[])
    {
        enum Stat
        {
            Stat_NoStat = 0,
            Stat_Win = 1,
            Stat_Loss = 2
        };

        if (someStats[aPlace] == Stat_NoStat)
        {
            std::cout << aPlace + 1 << ". " << "No stat" << std::endl;
        }
        else if (someStats[aPlace] == Stat_Win)
        {
            std::cout << aPlace + 1 << ". " << "Win" << std::endl;
        }
        else if (someStats[aPlace] == Stat_Loss)
        {
            std::cout << aPlace + 1 << ". " << "Loss" << std::endl;
        }
    }

    void ShowStatistics(int someStats[])
    {
        system("cls");
        std::cout << "======================" << std::endl;
        std::cout << "Recent game logs:" << std::endl;
        WriteStat(0, someStats);
        WriteStat(1, someStats);
        WriteStat(2, someStats);
        WriteStat(3, someStats);
        WriteStat(4, someStats);
        std::cout << "======================" << std::endl;
        std::cout << "\n\n";
        system("pause");
    }
}