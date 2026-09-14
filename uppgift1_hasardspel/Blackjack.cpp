#include <iostream>
#include <random>
#include "Shared.h"
#include "Blackjack.h"

namespace Blackjack
{
    void PlayBlackjack(bool gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[])
    {
		const int minBet = 1;
        int hitOrStand = 0;
        int drawnCard = 0;
        int cardCount = 0;
        int cardSum = 0;
        static signed int totalEarnings = 0;
        bool blackjack = true;
        bool drawingCards = true;

        enum HitOrStand
        {
            HitOrStand_Hit = 1,
            HitOrStand_Stand = 2
        };

        while (blackjack)
        {
            if (!(blackjack = SharedFunctions::CheckIfBanned(totalEarnings)))
            {
                system("cls");
                std::cout << "\nYou earned too much at this table. Do something else.\n\n";
                system("pause");
                break;
            }
            else if (!(blackjack = SharedFunctions::GetGameMenu(Game_Blackjack, totalEarnings, aPlayerWallet, aRewardMult)))
            {
                break;
            }

            drawnCard = 0;
            cardCount = 1;
            cardSum = 0;
            drawingCards = true;
            aRewardMult = 1;

            SharedFunctions::ShowGameIntro(Game_Blackjack, aPlayerWallet, aRewardMult);
            SharedFunctions::TotalEarningsMessage(totalEarnings);

            aBetAmount = SharedFunctions::GetPlayerBet(aBetAmount, aPlayerWallet, minBet);

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
            std::cout << "\nThe figure draws your first card...\n\n";
            system("pause");

            drawnCard = SharedFunctions::DrawCard();
            cardSum += drawnCard;
            system("cls");
            std::cout << "You drew: " << drawnCard << std::endl;
            std::cout << "Sum of cards: " << cardSum << std::endl;
            std::cout << "\nReward mult: X" << aRewardMult << std::endl;

            while (drawingCards)
            {
                std::cout << "\nTwo options. What will you do?\n";
                std::cout << "1. Hit\n";
                std::cout << "2. Stand\n";
                hitOrStand = SharedFunctions::GetPlayerNum(hitOrStand, HitOrStand_Stand, HitOrStand_Hit);

                switch (hitOrStand)
                {
                case HitOrStand_Hit:
                {
                    drawnCard = SharedFunctions::DrawCard();
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
                        SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
                        SharedFunctions::UpdateStatistics(GameResult_Loss, someStats);
                        totalEarnings -= aBetAmount;
                        if (aPlayerWallet <= 0)
                        {
                            std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                            gameRunning = false;
                            drawingCards = false;
                            blackjack = false;
                            system("pause");
                            break;
                        }
                        system("pause");
                        SharedFunctions::ShowStatistics(someStats);
                        drawingCards = false;
                    }

                    if (cardCount > 3)
                    {
                        aRewardMult += 1;
                        std::cout << "\nReward multiplier increased by 1";

                    }
                    else
                    {
                        std::cout << "\nReward multiplier will increase after 3 cards";

                    }
                    std::cout << "\nReward mult: X" << aRewardMult << std::endl;

                    break;
                }
                case HitOrStand_Stand:
                {
                    system("cls");
                    std::cout << "Sum of cards: " << cardSum << std::endl;
                    std::cout << "Reward mult: X" << aRewardMult << std::endl;

                    if (aBetAmount == (aBetAmount * aRewardMult))
                    {
                        std::cout << "\nYou chose to stand and got your kr back. (counts as win)" << std::endl;
                        std::cout << "Balance: " << aPlayerWallet << "kr \n\n";
                        SharedFunctions::UpdateStatistics(GameResult_Win, someStats);
                    }
                    else
                    {
                        std::cout << "\nYou won " << aBetAmount * aRewardMult << "kr" << std::endl;
                        SharedFunctions::UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
                        std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                        SharedFunctions::UpdateStatistics(GameResult_Win, someStats);
                    }
                    totalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
                    system("pause");
                    SharedFunctions::ShowStatistics(someStats);
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