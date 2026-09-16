#include <iostream>
#include <random>
#include "Misc.h"
#include "Roulette.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

namespace Roulette
{
	void InitializeWheel(int aWheel[wheelSize][colSize])
	{
		for (int i = 0; i < wheelSize; i++)
		{
			aWheel[i][0] = i;
		}

		aWheel[0][1] = Color_Green;
		aWheel[1][1] = Color_Red;
		aWheel[2][1] = Color_Black;
		aWheel[3][1] = Color_Red;
		aWheel[4][1] = Color_Black;
		aWheel[5][1] = Color_Red;
		aWheel[6][1] = Color_Black;
		aWheel[7][1] = Color_Red;
		aWheel[8][1] = Color_Black;
		aWheel[9][1] = Color_Red;
		aWheel[10][1] = Color_Black;
		aWheel[11][1] = Color_Black;
		aWheel[12][1] = Color_Red;
		aWheel[13][1] = Color_Black;
		aWheel[14][1] = Color_Red;
		aWheel[15][1] = Color_Black;
		aWheel[16][1] = Color_Red;
		aWheel[17][1] = Color_Black;
		aWheel[18][1] = Color_Red;
		aWheel[19][1] = Color_Red;
		aWheel[20][1] = Color_Black;
		aWheel[21][1] = Color_Red;
		aWheel[22][1] = Color_Black;
		aWheel[23][1] = Color_Red;
		aWheel[24][1] = Color_Black;
		aWheel[25][1] = Color_Red;
		aWheel[26][1] = Color_Black;
		aWheel[27][1] = Color_Red;
		aWheel[28][1] = Color_Black;
		aWheel[29][1] = Color_Black;
		aWheel[30][1] = Color_Red;
		aWheel[31][1] = Color_Black;
		aWheel[32][1] = Color_Red;
		aWheel[33][1] = Color_Black;
		aWheel[34][1] = Color_Red;
		aWheel[35][1] = Color_Black;
		aWheel[36][1] = Color_Red;
	}

	void PlayRoulette(Player::Player& aPlayer, int someStats[], int& someEarnings)
	{
		int wheel[wheelSize][colSize];
		InitializeWheel(wheel);
		const int maxNum = 4;
		const int minNum = 1;
		const int minBet = 1;
		int playerInput = 0;
		bool roulette = true;
		
		while (roulette)
		{
			if (!(roulette = Player::CheckIfBanned(someEarnings)))
			{
				system("cls");
				std::cout << "\nYou earned too much at this table. Do something else.\n\n";
				system("pause");
				break;
			}
			else if (!(roulette = GameFunctions::GetGameMenu(Misc::Game_Roulette, someEarnings, aPlayer.wallet, aPlayer.betMult)))
			{
				break;
			}

			GameFunctions::ShowGameIntro(Misc::Game_Blackjack, aPlayer.wallet, aPlayer.betMult);
			GameFunctions::TotalEarningsMessage(someEarnings);

			std::cout << "_______________________________ \n";
			system("pause");
			system("cls");
			std::cout << "Betting layout: \n\n";
			for (int i = 0; i < wheelSize; i++)
			{
				std::cout << wheel[i][0];
				switch (wheel[i][1])
				{
					case Color_Green:
					{
						std::cout << "(Green) ";
						break;
					}
					case Color_Red:
					{
						std::cout << "(Red) ";
						break;
					}
					case Color_Black:
					{
						std::cout << "(Black) ";
						break;
					}
					default:
						break;
				}

				if (i % 3 == 0)
				{
					std::cout << std::endl;
				}
				if (i % 12 == 0)
				{
					std::cout << std::endl;
				}
			}
			std::cout << std::endl;
			std::cout << "Betting options: (1-4)\n";
			std::cout << "1. Straight (30x bet)\n";
			std::cout << "2. Odd/Even (2x bet)\n";
			std::cout << "3. Red/Black (2x bet)\n";
			std::cout << "4. Column (3x bet)\n\n";
			
			std::cout << "What will you do?\n";
			playerInput = Player::GetPlayerNum(playerInput, maxNum, minNum);

			aPlayer.bet = Player::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

			system("cls");
			std::cout << "\nThe figure accepts your offer. \n";
			if (aPlayer.bet == aPlayer.wallet)
			{
				std::cout << "\n***HIGH STAKES***\n";
				std::cout << "Betting your whole wallet fills you with determination.\n";
			}

		}

		//placeholder
		std::cout << aPlayer.wallet; 
		std::cout << someStats[0];
		std::cout << someEarnings;

		system("pause");

	}
}