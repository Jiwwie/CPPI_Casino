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

		aWheel[0][Column_Color] = Color_Green;
		aWheel[1][Column_Color] = Color_Red;
		aWheel[2][Column_Color] = Color_Black;
		aWheel[3][Column_Color] = Color_Red;
		aWheel[4][Column_Color] = Color_Black;
		aWheel[5][Column_Color] = Color_Red;
		aWheel[6][Column_Color] = Color_Black;
		aWheel[7][Column_Color] = Color_Red;
		aWheel[8][Column_Color] = Color_Black;
		aWheel[9][Column_Color] = Color_Red;
		aWheel[10][Column_Color] = Color_Black;
		aWheel[11][Column_Color] = Color_Black;
		aWheel[12][Column_Color] = Color_Red;
		aWheel[13][Column_Color] = Color_Black;
		aWheel[14][Column_Color] = Color_Red;
		aWheel[15][Column_Color] = Color_Black;
		aWheel[16][Column_Color] = Color_Red;
		aWheel[17][Column_Color] = Color_Black;
		aWheel[18][Column_Color] = Color_Red;
		aWheel[19][Column_Color] = Color_Red;
		aWheel[20][Column_Color] = Color_Black;
		aWheel[21][Column_Color] = Color_Red;
		aWheel[22][Column_Color] = Color_Black;
		aWheel[23][Column_Color] = Color_Red;
		aWheel[24][Column_Color] = Color_Black;
		aWheel[25][Column_Color] = Color_Red;
		aWheel[26][Column_Color] = Color_Black;
		aWheel[27][Column_Color] = Color_Red;
		aWheel[28][Column_Color] = Color_Black;
		aWheel[29][Column_Color] = Color_Black;
		aWheel[30][Column_Color] = Color_Red;
		aWheel[31][Column_Color] = Color_Black;
		aWheel[32][Column_Color] = Color_Red;
		aWheel[33][Column_Color] = Color_Black;
		aWheel[34][Column_Color] = Color_Red;
		aWheel[35][Column_Color] = Color_Black;
		aWheel[36][Column_Color] = Color_Red;
	}

	void GetColumn(int aWheel[wheelSize][colSize], int aColumn)
	{ 
		std::cout << "Your numbers: \n";
		for (int i = (0 + aColumn); i < wheelSize; i+=3)
		{
			std::cout << aWheel[i][0] << " ";
		}
		std::cout << "\n";
	}

	void SpinBall(Misc::Random& aBall, int aMin, int aMax)
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

	void PlayRoulette(Player::Player& aPlayer, int someStats[], int& someEarnings)
	{
		int wheel[wheelSize][colSize];
		InitializeWheel(wheel);
		const int maxNum = 4;
		const int minNum = 1;
		const int minBet = 1;
		int playerInput = 0;
		bool roulette = true;
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

			GameFunctions::ShowGameIntro(Misc::Game_Roulette, aPlayer.wallet, aPlayer.betMult);
			GameFunctions::TotalEarningsMessage(someEarnings);

			std::cout << "_______________________________ \n";
			system("pause");
			system("cls");
			std::cout << "Betting layout: \n\n";
			for (int i = 0; i < wheelSize; i++)
			{
				std::cout << wheel[i][0];
				switch (wheel[i][Column_Color])
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
			playerInput = Player::GetPlayerNum(playerInput, maxNum, minNum);
			aPlayer.bet = Player::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

			system("cls");
			std::cout << "\nThe figure accepts your offer. \n";
			if (aPlayer.bet == aPlayer.wallet)
			{
				std::cout << "\n***HIGH STAKES***\n";
				std::cout << "Betting your whole wallet fills you with determination.\n";
			}


			switch (playerInput)
			{
				case BettingOption_Straight:
				{
					const int maxGuess = 36;
					const int minGuess = 0;
					aPlayer.betMult = 30;

					std::cout << "You chose to bet on a straight number.\n";
					std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
					std::cout << "Which number do you want? (0-36) " << "\n";
					playerInput = Player::GetPlayerNum(playerInput, maxGuess, minGuess);
					system("pause");

					SpinBall(aBall, 0, wheelSize-1);

					if (playerInput == aBall.ball)
					{
						std::cout << "\n\nYou win! Are you hacking?\n";
						std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
						Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
						Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
						someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
					}
					else
					{
						std::cout << "\nYou lose... XD\n";
						std::cout << "-" << aPlayer.bet << "kr!\n\n";
						Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
						Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
						someEarnings -= aPlayer.bet;
					}
					system("pause");

					break;
				}
				case BettingOption_OddEven:
				{
					const int maxChoice = 2;
					const int minChoice = 1;
					aPlayer.betMult = 2;

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
					playerInput = Player::GetPlayerNum(playerInput, maxChoice, minChoice);
					system("pause");

					SpinBall(aBall, 0, wheelSize - 1);

					switch (playerInput)
					{
						case Choice_Even:
						{
							if (aBall.ball % 2 == 0)
							{
								std::cout << "\n\nYou win! Are you hacking?\n";
								std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
								Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
								Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
								someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
							}
							else
							{
								std::cout << "\nYou lose... XD\n";
								std::cout << "-" << aPlayer.bet << "kr!\n\n";
								Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
								Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
								someEarnings -= aPlayer.bet;
							}
							break;
						}
						case Choice_Odd:
						{
							if (aBall.ball % 2 != 0)
							{
								std::cout << "\n\nYou win!\n";
								std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
								Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
								Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
								someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
							}
							else
							{
								std::cout << "\nYou lose... XD\n";
								std::cout << "-" << aPlayer.bet << "kr!\n\n";
								Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
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
					const int maxChoice = 2;
					const int minChoice = 1;
					aPlayer.betMult = 2;

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
					playerInput = Player::GetPlayerNum(playerInput, maxChoice, minChoice);
					system("pause");

					SpinBall(aBall, 0, wheelSize - 1);
					std::cout << '\n' << aBall.ball << " is... ";
					switch (wheel[aBall.ball][Column_Color])
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

					switch (playerInput)
					{
					case Choice_Red:
					{
						if (wheel[aBall.ball][Column_Color] == Color_Red)
						{
							std::cout << "\n\nYou win!\n";
							std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
							Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
							Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
							someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
						}
						else
						{
							std::cout << "\nYou lose... XD\n";
							std::cout << "-" << aPlayer.bet << "kr!\n\n";
							Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
							Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
							someEarnings -= aPlayer.bet;
						}
						break;
					}
					case Choice_Black:
					{
						if (wheel[aBall.ball][Column_Color] == Color_Black)
						{
							std::cout << "\n\nYou win!\n";
							std::cout << aPlayer.bet * aPlayer.betMult << "kr added to wallet.\n\n";
							Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
							Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
							someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
						}
						else
						{
							std::cout << "\nYou lose... XD\n";
							std::cout << "-" << aPlayer.bet << "kr!\n\n";
							Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
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
					const int maxCol = 3;
					const int minCol = 1;
					aPlayer.betMult = 3;

					std::cout << "You chose to bet on a column.\n";
					std::cout << "You're betting " << aPlayer.bet << "kr.\n\n";
					std::cout << "Which column do you want? (1-3) " << "\n";
					playerInput = Player::GetPlayerNum(playerInput, maxCol, minCol);

					GetColumn(wheel, playerInput);
					system("pause");

					SpinBall(aBall, 0, wheelSize - 1);


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
}