#include <iostream>
#include <random>
#include "Misc.h"
#include "RockPaperScissors.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

void RPS::RollRPS(Misc::Random& aRPS, int aMin, int aMax)
{
	std::random_device seed;
	std::mt19937 rndEngine(seed());
	std::uniform_int_distribution<int> rndDist(aMin, aMax);
	aRPS.rps = rndDist(rndEngine);
}

void RPS::PlayRPS(Player::PlayerData& aPlayer, int someStats[], int& someEarnings)
{
	Misc::Random figureInput = {};
	Misc::Const consts = {};
	bool rockPaperScissors = true;

	enum RPS
	{
		RPS_Rock = 1,
		RPS_Paper = 2,
		RPS_Scissors = 3
	};

	while (rockPaperScissors)
	{
        if (!(rockPaperScissors = Player::CheckIfBanned(someEarnings)))
        {
            system("cls");
            std::cout << "\nYou earned too much at this table. Do something else.\n\n";
            system("pause");
            break;
        }
        else if (!(rockPaperScissors = GameFunctions::GetGameMenu(Misc::Game_RockPaperScissors, someEarnings, aPlayer.wallet, aPlayer.betMult)))
        {
            break;
        }

        GameFunctions::ShowGameIntro(Misc::Game_RockPaperScissors, aPlayer.wallet, aPlayer.betMult);
        GameFunctions::TotalEarningsMessage(someEarnings);

        Player::GetPlayerBet(aPlayer, aPlayer.wallet, consts.MIN_BET);

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
        aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.RPS_MAX_INPUT, consts.RPS_MIN_INPUT);
        RollRPS(figureInput, consts.RPS_MIN_INPUT, consts.RPS_MAX_INPUT);


		system("cls");
		std::cout << "\nThe figure throws its hand dramatically...\n";

		switch (aPlayer.input)
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

        switch (aPlayer.input)
        {
			case RPS_Rock:
				if (figureInput.rps == RPS_Scissors)
				{
					std::cout << "\nYou win! Your bet was doubled.\n";
					Player::UpdatePlayerWallet(aPlayer, '+');
					Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
					someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
				}
				else if (figureInput.rps == RPS_Paper)
				{
					std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
					Player::UpdatePlayerWallet(aPlayer, '-');
					Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
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
					Player::UpdatePlayerWallet(aPlayer, '+');
					Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
					someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
				}
				else if (figureInput.rps == RPS_Scissors)
				{
					std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
					Player::UpdatePlayerWallet(aPlayer, '-');
					Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
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
					Player::UpdatePlayerWallet(aPlayer, '+');
					Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
					someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
				}
				else if (figureInput.rps == RPS_Rock)
				{
					std::cout << "\nYou lose! -" << aPlayer.bet << "kr\n";
					Player::UpdatePlayerWallet(aPlayer, '-');
					Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
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
			Statistics::ShowStatistics(someStats);
		}
	}
}
