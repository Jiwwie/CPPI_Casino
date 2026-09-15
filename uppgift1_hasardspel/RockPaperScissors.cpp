#include <iostream>
#include <random>
#include "Shared.h"
#include "RockPaperScissors.h"

namespace RockPaperScissors
{
	void PlayRPS(bool aGameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[], int& someEarnings)
	{
		const int maxNum = 3;
		const int minNum = 1;
		const int minBet = 1;
		int playerInput = 0;
		Random figureInput = {};
		bool rockPaperScissors = true;

		enum RPS
		{
			RPS_Rock = 1,
			RPS_Paper = 2,
			RPS_Scissors = 3
		};

		while (rockPaperScissors)
		{
            if (!(rockPaperScissors = Shared::CheckIfBanned(someEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(rockPaperScissors = Shared::GetGameMenu(Game_RockPaperScissors, someEarnings, aPlayerWallet, aRewardMult)))
            {
                break;
            }

            Shared::ShowGameIntro(Game_RockPaperScissors, aPlayerWallet, aRewardMult);
            Shared::TotalEarningsMessage(someEarnings);

            aBetAmount = Shared::GetPlayerBet(aBetAmount, aPlayerWallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aBetAmount == aPlayerWallet)
            {
                std::cout << "\n***HIGH STAKES***\n";
                std::cout << "Betting your whole wallet fills you with determination.\n";
            }
            std::cout << "_______________________________ \n";
            system("pause");
            system("cls");
            std::cout << "_______________________________ \n";
            std::cout << "What will you throw? (1-3)\n";
            std::cout << "1. Rock\n";
            std::cout << "2. Paper\n";
            std::cout << "3. Scissors\n";
            playerInput = Shared::GetPlayerNum(playerInput, maxNum, minNum);
            Shared::RollRPS(figureInput);

			system("cls");
			std::cout << "\nThe figure throws its hand dramatically...\n\n";
			std::cout << "You threw: " << playerInput << std::endl;
			std::cout << "The figure threw: " << figureInput.rps << std::endl;
			system("pause");

            switch (playerInput)
            {
				case RPS_Rock:
					if (figureInput.rps == RPS_Scissors)
					{
						std::cout << "\nYou win!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Win, someStats);
						someEarnings += (aBetAmount * aRewardMult) - aBetAmount;
					}
					else if (figureInput.rps == RPS_Paper)
					{
						std::cout << "\nYou lose!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Loss, someStats);
						someEarnings -= aBetAmount;
					}
					else
					{
						std::cout << "\nIt's a tie!\n";
					}
					break;

				case RPS_Paper:
					if (figureInput.rps == RPS_Rock)
					{
						std::cout << "\nYou win!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Win, someStats);
						someEarnings += (aBetAmount * aRewardMult) - aBetAmount;
					}
					else if (figureInput.rps == RPS_Scissors)
					{
						std::cout << "\nYou lose!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Loss, someStats);
						someEarnings -= aBetAmount;
					}
					else
					{
						std::cout << "\nIt's a tie!\n";
					}
					break;

				case RPS_Scissors:
					if (figureInput.rps == RPS_Paper)
					{
						std::cout << "\nYou win!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Win, someStats);
						someEarnings += (aBetAmount * aRewardMult) - aBetAmount;
					}
					else if (figureInput.rps == RPS_Rock)
					{
						std::cout << "\nYou lose!\n";
						Shared::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
						Shared::UpdateStatistics(GameResult_Loss, someStats);
						someEarnings -= aBetAmount;
					}
					else
					{
						std::cout << "\nIt's a tie!\n";
					}
					break;

				default:
					break;
            }

			system("pause");

		}
	}
}
