#include <iostream>
#include <random>
#include "Misc.h"
#include "Blackjack.h"
#include "Player.h"
#include "GameFunctions.h"
#include "Statistics.h"

namespace Blackjack
{
    int DrawCard(int aMin, int aMax)
    {
        std::random_device seed;
        std::mt19937 rndEngine(seed());
        std::uniform_int_distribution<int> rndDist(aMin, aMax);
        return rndDist(rndEngine);
    }

    void PlayBlackjack(Player::Player& aPlayer, int someStats[], int& someEarnings)
    {
		const int minBet = 1;
        int hitOrStand = 0;
        int drawnCard = 0;
        int cardCount = 0;
        int cardSum = 0;
        bool blackjack = true;
        bool drawingCards = true;

        enum HitOrStand
        {
            HitOrStand_Hit = 1,
            HitOrStand_Stand = 2
        };

        while (blackjack)
        {
            if (!(blackjack = Player::CheckIfBanned(someEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(blackjack = GameFunctions::GetGameMenu(Misc::Game_Blackjack, someEarnings, aPlayer.wallet, aPlayer.betMult)))
            {
                break;
            }

            drawnCard = 0;
            cardCount = 1;
            cardSum = 0;
            drawingCards = true;
            aPlayer.betMult = 1;

            GameFunctions::ShowGameIntro(Misc::Game_Blackjack, aPlayer.wallet, aPlayer.betMult);
            GameFunctions::TotalEarningsMessage(someEarnings);

            aPlayer.bet = Player::GetPlayerBet(aPlayer.bet, aPlayer.wallet, minBet);

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
            std::cout << "\nThe figure draws your first card...\n\n";
            system("pause");

            drawnCard = DrawCard(1, 11);
            cardSum += drawnCard;
            system("cls");
            std::cout << "You drew: " << drawnCard << std::endl;
            std::cout << "Sum of cards: " << cardSum << std::endl;
            std::cout << "\nReward mult: X" << aPlayer.betMult << std::endl;

            while (drawingCards)
            {
                std::cout << "\nTwo options. What will you do?\n";
                std::cout << "1. Hit\n";
                std::cout << "2. Stand\n";
                hitOrStand = Player::GetPlayerNum(hitOrStand, HitOrStand_Stand, HitOrStand_Hit);

                switch (hitOrStand)
                {
                case HitOrStand_Hit:
                {
                    drawnCard = DrawCard(1, 11);
                    cardSum += drawnCard;
                    cardCount += 1;

                    system("cls");
                    std::cout << "You drew: " << drawnCard << std::endl;
                    std::cout << "Sum of cards: " << cardSum << std::endl;
                    std::cout << "Card count: " << cardCount << " cards" << std::endl;

                    if (cardSum > 21)
                    {
                        std::cout << "\n\nCard sum went over 21.\n";
                        std::cout << "You lose.\n";
                        Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '-', aPlayer.wallet);
                        Statistics::UpdateStatistics(Statistics::GameResult_Loss, someStats);
                        someEarnings -= aPlayer.bet;
                        if (aPlayer.wallet <= 0)
                        {
                            std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                            aPlayer.playing = false;
                            drawingCards = false;
                            blackjack = false;
                            system("pause");
                            break;
                        }
                        system("pause");
                        Statistics::ShowStatistics(someStats);
                        drawingCards = false;
                    }

                    if (cardCount > 3)
                    {
                        aPlayer.betMult += 1;
                        std::cout << "\nReward multiplier increased by 1";

                    }
                    else
                    {
                        std::cout << "\nReward multiplier will increase after 3 cards";

                    }
                    std::cout << "\nReward mult: X" << aPlayer.betMult << std::endl;

                    break;
                }
                case HitOrStand_Stand:
                {
                    system("cls");
                    std::cout << "Sum of cards: " << cardSum << std::endl;
                    std::cout << "Reward mult: X" << aPlayer.betMult << std::endl;

                    if (aPlayer.bet == (aPlayer.bet * aPlayer.betMult))
                    {
                        std::cout << "\nYou chose to stand and got your kr back. (counts as win)" << std::endl;
                        std::cout << "Balance: " << aPlayer.wallet << "kr \n\n";
                        Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
                    }
                    else
                    {
                        std::cout << "\nYou won " << aPlayer.bet * aPlayer.betMult << "kr" << std::endl;
                        Player::UpdatePlayerWallet(aPlayer.bet, aPlayer.betMult, '+', aPlayer.wallet);
                        std::cout << "New balance: " << aPlayer.wallet << "kr \n\n";
                        Statistics::UpdateStatistics(Statistics::GameResult_Win, someStats);
                    }
                    someEarnings += (aPlayer.bet * aPlayer.betMult) - aPlayer.bet;
                    system("pause");
                    Statistics::ShowStatistics(someStats);
                    drawingCards = false;
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
}