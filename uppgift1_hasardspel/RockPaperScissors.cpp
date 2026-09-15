#include <iostream>
#include <random>
#include "Shared.h"
#include "Structs.h"
#include "RockPaperScissors.h"

namespace RockPaperScissors
{
	void RollRPS(Struct::Random& aRPS, int aMin, int aMax)
	{
		std::random_device seed;
		std::mt19937 rndEngine(seed());
		std::uniform_int_distribution<int> rndDist(aMin, aMax);
		aRPS.rps = rndDist(rndEngine);
	}

	void PlayRPS(Struct::Player& aPlayer, int someStats[], int& someEarnings)
	{
		const int maxNum = 3;
		const int minNum = 1;
		const int minBet = 1;
		int playerInput = 0;
		Struct::Random figureInput = {};
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
            else if (!(rockPaperScissors = Shared::GetGameMenu(Shared::Game_RockPaperScissors, someEarnings, aPlayer.wallet, aPlayer.betMult)))
            {
                break;
            }

            Shared::ShowGameIntro(Shared::Game_RockPaperScissors, aPlayer.wallet, aPlayer.betMult);
            Shared::TotalEarningsMessage(someEarnings);

            aPlayer.bet = Shared::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

            system("cls");
            std::cout << "\nThe figure accepts your offer. \n";
            if (aPlayer.bet == aPlayer.wallet)
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
            RollRPS(figureInput, minNum, maxNum);


			system("cls");
			std::cout << "\nThe figure throws its hand dramatically...\n";

			switch (playerInput)
			{
				case RPS_Rock:
					std::cout << "You threw: Rock\n";
					break;
				case RPS_Paper:
					std::cout << "You threw: Paper\n";
					break;
				case RPS_Scissors:
					std::cout << "You threw: Scissors\n";
					break;
				default:
					break;
			}

			switch (figureInput.rps)
			{
				case RPS_Rock:
					std::cout << "The figure threw: Rock\n";
					break;
				case RPS_Paper:
					std::cout << "The figure threw: Paper\n";
					break;
				case RPS_Scissors:
					std::cout << "The figure threw: Scissors\n";
					break;
				default:
					break;
			}

			system("pause");


            switch (playerInput)
            {
				case RPS_Rock:
					if (figureInput.rps == RPS_Scissors)
					{
						std::cout << "\nYou win! Your bet was doubled.\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else if (figureInput.rps == RPS_Paper)
					{
						std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					else
					{
						std::cout << "\nIt's a tie! You got your money back.\n";
					}
					break;

				case RPS_Paper:
					if (figureInput.rps == RPS_Rock)
					{
						std::cout << "\nYou win! Your bet was doubled.\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else if (figureInput.rps == RPS_Scissors)
					{
						std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					else
					{
						std::cout << "\nIt's a tie! You got your money back.\n";
					}
					break;

				case RPS_Scissors:
					if (figureInput.rps == RPS_Paper)
					{
						std::cout << "\nYou win! Your bet was doubled.\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else if (figureInput.rps == RPS_Rock)
					{
						std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
						Shared::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
						Shared::UpdateStatistics(Shared::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					else
					{
						std::cout << "\nIt's a tie! You got your money back.\n";
					}
					break;

				default:
					break;
            }

			system("pause");

			if (aPlayer.wallet <= 0)
			{
				std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
				aPlayer.playing = false;
				rockPaperScissors = false;
				system("pause");
				break;
			}
			else
			{
				Shared::ShowStatistics(someStats);
			}
		}
	}
}
