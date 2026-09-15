#include <iostream>
#include <random>
#include "Misc.h"
#include "Shared.h"

namespace Shared
{
    void ShowMainMenu()
    {
        system("cls");
        std::cout << " =======================\n";
        std::cout << "||       CASINO        ||\n";
        std::cout << " =======================\n\n";

        std::cout << "\"It's a beautiful day outside,\n";
        std::cout << " Birds are singing,\n";
        std::cout << " Flowers are blooming...\n";
        std::cout << " On days like these,\n";
        std::cout << " Kids like you should be spending your CSN\"\n\n";

        std::cout << "What do you want to do? (1-5) " << std::endl;
        std::cout << "1. Dice Game" << std::endl;
        std::cout << "2. Odd or Even" << std::endl;
        std::cout << "3. Blackjack (lite)" << std::endl;
        std::cout << "4. Rock Paper Scissors" << std::endl;
        std::cout << "5. Show statistics" << std::endl;
        std::cout << "6. Leave Casino\n" << std::endl;
    }

}


