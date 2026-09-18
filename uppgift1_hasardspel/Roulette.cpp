#include <iostream>
#include <random>
#include "Misc.h"
#include "Roulette.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

void Roulette::InitializeWheel(int aWheel[wheelSize][colSize])
{
	const int color = 1;

	for (int i = 0; i < wheelSize; i++)
	{
		aWheel[i][0] = i;
	}

	aWheel[0][color] = Color_Green;
	aWheel[1][color] = Color_Red;
	aWheel[2][color] = Color_Black;
	aWheel[3][color] = Color_Red;
	aWheel[4][color] = Color_Black;
	aWheel[5][color] = Color_Red;
	aWheel[6][color] = Color_Black;
	aWheel[7][color] = Color_Red;
	aWheel[8][color] = Color_Black;
	aWheel[9][color] = Color_Red;
	aWheel[10][color] = Color_Black;
	aWheel[11][color] = Color_Black;
	aWheel[12][color] = Color_Red;
	aWheel[13][color] = Color_Black;
	aWheel[14][color] = Color_Red;
	aWheel[15][color] = Color_Black;
	aWheel[16][color] = Color_Red;
	aWheel[17][color] = Color_Black;
	aWheel[18][color] = Color_Red;
	aWheel[19][color] = Color_Red;
	aWheel[20][color] = Color_Black;
	aWheel[21][color] = Color_Red;
	aWheel[22][color] = Color_Black;
	aWheel[23][color] = Color_Red;
	aWheel[24][color] = Color_Black;
	aWheel[25][color] = Color_Red;
	aWheel[26][color] = Color_Black;
	aWheel[27][color] = Color_Red;
	aWheel[28][color] = Color_Black;
	aWheel[29][color] = Color_Black;
	aWheel[30][color] = Color_Red;
	aWheel[31][color] = Color_Black;
	aWheel[32][color] = Color_Red;
	aWheel[33][color] = Color_Black;
	aWheel[34][color] = Color_Red;
	aWheel[35][color] = Color_Black;
	aWheel[36][color] = Color_Red;
}

void Roulette::GetColumn(int aWheel[wheelSize][colSize], int aColumn)
{ 
	Misc::Const consts = {};

	std::cout << "Your numbers: \n";
	for (int i = (0 + aColumn); i < wheelSize; i+=consts.ROULETTE_COL_DISTANCE)
	{
		std::cout << aWheel[i][0] << " ";
	}
	std::cout << "\n";
}

void Roulette::SpinBall(Misc::Random& aBall, int aMin, int aMax)
{
	std::random_device seed;
	std::mt19937 rndEngine(seed());
	std::uniform_int_distribution<int> rndDist(aMin, aMax);
	aBall.ball = rndDist(rndEngine);

	std::cout << "\n========================================= " << "\n";
	std::cout << "The figure spins the ball dramatically... " << "\n";
	std::cout << "It lands on... " << "\n" << aBall.ball << "!\n\n";
	system("pause");
}

void Roulette::PlayRoulette(Player::PlayerData& aPlayer, int someStats[], int& someEarnings)
{
	int wheel[wheelSize][colSize];
	InitializeWheel(wheel);
	bool roulette = true;
	Misc::Const consts = {};
	Misc::Random aBall = {};
		
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

		aPlayer.betMult = consts.DEFAULT_BET_MULT;

		GameFunctions::ShowGameIntro(Misc::Game_Roulette, aPlayer.wallet, aPlayer.betMult);
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
					std::cout << "(G) ";
					break;
				}
				case Color_Red:
				{
					std::cout << "(R) |";
					break;
				}
				case Color_Black:
				{
					std::cout << "(B) |";
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
		std::cout << "1. Straight  (30x bet)\n";
		std::cout << "2. Odd/Even  (2x bet)\n";
		std::cout << "3. Red/Black (2x bet)\n";
		std::cout << "4. Column    (3x bet)\n\n";
			
		std::cout << "What will you do?\n";
		aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.ROULETTE_MAX_MENU, consts.ROULETTE_MIN_MENU);
		Player::GetPlayerBet(aPlayer, aPlayer.wallet, consts.MIN_BET);

		system("cls");
		std::cout << "\nThe figure accepts your offer. \n";
		if (aPlayer.bet == aPlayer.wallet)
		{
			std::cout << "\n***HIGH STAKES***\n";
			std::cout << "Betting your whole wallet fills you with determination.\n";
		}


		switch (aPlayer.input)
		{
			case BettingOption_Straight:
			{
				aPlayer.betMult = consts.STRAIGHT_MULT;

				std::cout << "You chose to bet on a straight number.\n";
				std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
				std::cout << "Which number do you want? (0-36) " << "\n";
				aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.ROULETTE_MAX_NUM, consts.ROULETTE_MIN_NUM);
				system("pause");

				SpinBall(aBall, consts.ROULETTE_MIN_NUM, consts.ROULETTE_MAX_NUM);

				if (aPlayer.input == aBall.ball)
				{
					std::cout << "\n\nYou win! Are you hacking?\n";
					std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
					Player::UpdatePlayerWallet(aPlayer, '+');
					Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
					someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
				}
				else
				{
					std::cout << "\nYou lose... XD\n";
					std::cout << "-" << aPlayer.bet << "kr!\n\n";
					Player::UpdatePlayerWallet(aPlayer, '-');
					Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
					someEarnings -= aPlayer.bet;
				}
				system("pause");

				break;
			}
			case BettingOption_OddEven:
			{
				aPlayer.betMult = consts.DEFAULT_BET_MULT;

				enum Choice
				{
					Choice_Even = 1,
					Choice_Odd = 2
				};

				std::cout << "You chose to bet on odd or even.\n";
				std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
				std::cout << "Two options. Even or odd?\n";
				std::cout << "1. Even\n";
				std::cout << "2. Odd\n";
				aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.ROULETTE_MAX_TWO_OPT, consts.ROULETTE_MIN_TWO_OPT);
				system("pause");

				SpinBall(aBall, consts.ROULETTE_MIN_NUM, consts.ROULETTE_MAX_NUM);

				switch (aPlayer.input)
				{
					case Choice_Even:
					{
						if (aBall.ball % 2 == 0 && aBall.ball != 0)
						{
							std::cout << "\n\nYou win! Are you hacking?\n";
							std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
							Player::UpdatePlayerWallet(aPlayer, '+');
							Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
							someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
						}
						else
						{
							std::cout << "\nYou lose... XD\n";
							std::cout << "-" << aPlayer.bet << "kr!\n\n";
							Player::UpdatePlayerWallet(aPlayer, '-');
							Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
							someEarnings -= aPlayer.bet;
						}
						break;
					}
					case Choice_Odd:
					{
						if (aBall.ball % 2 != 0 && aBall.ball != 0)
						{
							std::cout << "\n\nYou win!\n";
							std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
							Player::UpdatePlayerWallet(aPlayer, '+');
							Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
							someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
						}
						else
						{
							std::cout << "\nYou lose... XD\n";
							std::cout << "-" << aPlayer.bet << "kr!\n\n";
							Player::UpdatePlayerWallet(aPlayer, '-');
							Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
							someEarnings -= aPlayer.bet;
						}
						break;
					}
					default:
						break;
				}
				system("pause");
				break;
			}
			case BettingOption_RedBlack:
			{
				aPlayer.betMult = consts.DEFAULT_BET_MULT;

				enum Choice
				{
					Choice_Red = 1,
					Choice_Black = 2
				};

				std::cout << "You chose to bet on red or black.\n";
				std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
				std::cout << "Two options. Red or black?\n";
				std::cout << "1. Red\n";
				std::cout << "2. Black\n";
				aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.ROULETTE_MAX_TWO_OPT, consts.ROULETTE_MIN_TWO_OPT);
				system("pause");

				SpinBall(aBall, consts.ROULETTE_MIN_NUM, consts.ROULETTE_MAX_NUM);
				std::cout << '\n' << aBall.ball << " is... ";
				switch (wheel[aBall.ball][1])
				{
					case Color_Green:
					{
						std::cout << "Green!";
						break;
					}
					case Color_Red:
					{
						std::cout << "Red!";
						break;
					}
					case Color_Black:
					{
						std::cout << "Black!";
						break;
					}
					default:
						break;
				}

				switch (aPlayer.input)
				{
				case Choice_Red:
				{
					if (wheel[aBall.ball][1] == Color_Red)
					{
						std::cout << "\n\nYou win!\n";
						std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
						Player::UpdatePlayerWallet(aPlayer, '+');
						Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else
					{
						std::cout << "\nYou lose... XD\n";
						std::cout << "-" << aPlayer.bet << "kr!\n\n";
						Player::UpdatePlayerWallet(aPlayer, '-');
						Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					break;
				}
				case Choice_Black:
				{
					if (wheel[aBall.ball][1] == Color_Black)
					{
						std::cout << "\n\nYou win!\n";
						std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
						Player::UpdatePlayerWallet(aPlayer, '+');
						Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else
					{
						std::cout << "\nYou lose... XD\n";
						std::cout << "-" << aPlayer.bet << "kr!\n\n";
						Player::UpdatePlayerWallet(aPlayer, '-');
						Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					break;
				}
				default:
					break;
				}
				system("pause");
				break;
			}
			case BettingOption_Column:
			{
				bool inCol = false;
				aPlayer.betMult = consts.HIGH_STAKES_MULT;

				std::cout << "You chose to bet on a column.\n";
				std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
				std::cout << "Which column do you want? (1-3) " << "\n";
				aPlayer.input = Player::GetPlayerNum(aPlayer.input, consts.ROULETTE_MAX_COL, consts.ROULETTE_MIN_COL);

				GetColumn(wheel, aPlayer.input);
				system("pause");

				SpinBall(aBall, consts.ROULETTE_MIN_NUM, consts.ROULETTE_MAX_NUM);
				for (int i = (0 + aPlayer.input) ; i < wheelSize; i+=consts.ROULETTE_COL_DISTANCE)
				{
					if (aBall.ball == i)
					{
						std::cout << "\n\nYou win!\n";
						std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
						Player::UpdatePlayerWallet(aPlayer, '+');
						Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
						inCol = true;
						break;
					}
					else
					{
						continue;
					}
				}

				if (inCol != true)
				{
					std::cout << "\nYou lose... XD\n";
					std::cout << "-" << aPlayer.bet << "kr!\n\n";
					Player::UpdatePlayerWallet(aPlayer, '-');
					Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
					someEarnings -= aPlayer.bet;
					system("pause");
				}

				break;
			}
			default:
				break;
		}

		if (aPlayer.wallet <= 0)
		{
			std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
			aPlayer.playing = false;
			roulette = false;
			system("pause");
			break;
		}
		else
		{
			Statistics::ShowStatistics(someStats);
		}
	}
}
