#include <iostream>
#include <cstdlib>
#include <random>

std::random_device seed;
std::mt19937 rndEngine(seed());

struct Dice
{
    int one;
    int two;
};

void ShowMainMenu();
void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult);
void ClearInputBuffer();
void UpdatePlayerWallet(int aBetAmount, int aMultiplier, char anOperator, int& aPlayerWallet);
void UpdateStatistics(int aStat, int someStats[]);
int GetPlayerNum(int aPlayerNum, int aMax, int aMin);
int GetPlayerBet(int aPlayerNum, int aMax, int aMin);
int GetGameMenu(int aGameNum, int aTotalEarnings, int aPlayerWallet, int aRewardMult);
int CheckIfBanned(int aTotalEarnings);
void TotalEarningsMessage(int aTotalEarnings);
void WriteStat(int aPlace, int someStats[]);
void RollDice(Dice& aDie);
int DrawCard();
void PlayDiceGame(bool& aGameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[]);
void PlayOddOrEven(bool& aGameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[]);
void PlayBlackjack(bool& aGameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[]);
void ShowStatistics(int someStats[]);


//MAIN_______________________________________________________________________________________________________
int main()
{
    enum ActiveGame
    {
		ActiveGame_DiceGame = 1,
		ActiveGame_OddOrEven = 2,
		ActiveGame_Blackjack = 3,
		ActiveGame_Statistics = 4,
		ActiveGame_LeaveCasino = 5
    };

    int stats[5] =
    {
       0,
       0,
       0,
       0,
       0
    };

    int activeGame = 0;
    bool gameRunning = true;
    int playerWallet = 1000;
    int rewardMult = 2;
    int betAmount = 0;

    while (gameRunning)
    {
        ShowMainMenu();
        std::cin >> activeGame;
        ClearInputBuffer();

        switch (activeGame)
        {
            case ActiveGame_DiceGame:
            {
                PlayDiceGame(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_OddOrEven:
            {
                PlayOddOrEven(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_Blackjack:
            {
                PlayBlackjack(gameRunning, playerWallet, rewardMult, betAmount, stats);
                break;
            }
            case ActiveGame_Statistics:
            {
                ShowStatistics(stats);
                break;
            }
            case ActiveGame_LeaveCasino:
            {
                system("cls");
                std::cout << "\nYou left the casino with " << playerWallet << "kr to your name.\n\n\n";
                system("pause");
                gameRunning = false;
                break;
            }
            default: 
            {
                break;
            }
        }
    }
}

//FUNCTIONS___________________________________________________________
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
    std::cout << "4. Show statistics" << std::endl;
    std::cout << "5. Leave Casino\n" << std::endl;
}

void ShowGameIntro(int anIntroKey, int aPlayerWallet, int aRewardMult)
{
    system("cls");
    std::cout << " =======================\n";
    std::cout << "||       CASINO        ||\n";
    std::cout << " =======================\n\n";

    std::cout << "You have " << aPlayerWallet << "kr \n";
    std::cout << "Reward multiplier: X" << aRewardMult << "\n\n";

    switch (anIntroKey)
    {
        case 1:
        {
            std::cout << "A mysterious figure steps forth and reveals a pair of dice.\n";
            std::cout << "\"If you can guess the sum of these when I throw them...\"\n";
            std::cout << "\"I'll reward you handsomely.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        case 2:
        {
            std::cout << "A mysterious figure steps forth and reveals a pair of dice.\n";
            std::cout << "\"If you can guess if these will roll odd or even\"\n";
            std::cout << "\"I'll reward you handsomely.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        case 3:
        {
            std::cout << "A mysterious figure steps forth and reveals a stack of cards.\n";
            std::cout << "\"Your goal is to get as close to 21 as possible.\"\n";
            std::cout << "\"I'll increase your reward for each card.\"\n";
            std::cout << "\"Go over 21, and your money is mine.\"\n\n";

            std::cout << "You are filled with determination.\n\n";
            break;
        }
        default:
        {
            std::cout << "Key does not exist\n";
            break;
        }
    }
}

void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void UpdatePlayerWallet(int aBetAmount, int aMultiplier, char anOperator, int& aPlayerWallet)
{
    switch (anOperator)
    {
        case '+':
        {
            aPlayerWallet = (aPlayerWallet + (aBetAmount * aMultiplier)) - aBetAmount;
            break;
        }
        case '-':
        {
            aPlayerWallet = aPlayerWallet - aBetAmount;
            break;
        }
        default:
            break;
    }
}

void UpdateStatistics(int aStat, int someStats[])
{
    for (int i = 4; i > 0; i--)
    {
        someStats[i] = someStats[i - 1];
    }
    someStats[0] = aStat;
}

int GetPlayerNum(int aPlayerNum, int aMax, int aMin)
{
    std::cin >> aPlayerNum;
    while (aPlayerNum > aMax || aPlayerNum < aMin || std::cin.fail())
    {
        ClearInputBuffer();
        std::cout << "\nInvalid option. ";
        std::cin >> aPlayerNum;
    }
    ClearInputBuffer();
    return aPlayerNum;
}

int GetPlayerBet(int aPlayerNum, int aMax, int aMin)
{
    std::cout << "\n====================================\n";
    std::cout << "The figure approaches you and opens its hand.\n";
    std::cout << "How much will you bet? \n";

    std::cin >> aPlayerNum;

    while (aPlayerNum > aMax || aPlayerNum < aMin || std::cin.fail())
    {
        if (aPlayerNum > aMax)
        {
            ClearInputBuffer();
            std::cout << "\nYou don't have that much... \n";
            std::cout << "What is your bet? \n";
            std::cin >> aPlayerNum;
        }
        else if (aPlayerNum < aMin)
        {
            ClearInputBuffer();
            std::cout << "\nAre you trying to rip me off? \n";
            std::cout << "What is your bet? \n";
            std::cin >> aPlayerNum;
        }
        else
        {
            ClearInputBuffer();
            std::cout << "\nInvalid option. ";
            std::cin >> aPlayerNum;
        }
    }
    ClearInputBuffer();
    return aPlayerNum;
}

int GetGameMenu(int aGameNum, int aTotalEarnings, int aPlayerWallet, int aRewardMult)
{
    bool menu = true;
    int menuChoice = 0;
    bool startGame = false;

    while (menu)
    {
        system("cls");
        std::cout << "You have " << aPlayerWallet << "kr \n";
        std::cout << "Reward multiplier: X" << aRewardMult << "\n";
        TotalEarningsMessage(aTotalEarnings);

        std::cout << "\n\nGAME MENU\n";
        std::cout << "1. Play game\n";
        std::cout << "2. Show rules\n";
        std::cout << "3. Back to main menu\n";
        std::cout << "===================================\n\n";

        std::cout << "What will you do? ";
        menuChoice = GetPlayerNum(menuChoice, 3, 1);

        switch (menuChoice)
        {
            case 1:
            {
                startGame = true;
                menu = false;
                break;
            }
            case 2:
            {
                system("cls");
                std::cout << "RULES:\n";
                if (aGameNum == 1)
                {
                    std::cout << "1. Guess any number between 2-12\n";
                    std::cout << "2. Two six-sided dice are rolled\n";
                    std::cout << "3. If you guessed the sum, you win\n\n";
                }
                else if (aGameNum == 2)
                {
                    std::cout << "1. Place your bet, odd or even\n";
                    std::cout << "2. Two six-sided dice are rolled\n";
                    std::cout << "3. If both sides show odd/even, you win\n";
                    std::cout << "3. Winning multiple times in a row will increase your reward multiplier\n\n\n";
                }
                else if (aGameNum == 3)
                {
                    std::cout << "1. The deck contains cards with values 1-11.\n";
                    std::cout << "2. Hit to draw a card, stand to end round.\n";
                    std::cout << "3. Each card after your third increases reward.\n";
                    std::cout << "3. If your sum oversteps 21, you lose.\n\n\n";
                }
                system("pause");
                break;

            }
            case 3:
            {
                menu = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return startGame;
}

int CheckIfBanned(int aTotalEarnings)
{
    if (aTotalEarnings >= 5000)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void TotalEarningsMessage(int aTotalEarnings)
{
    if (aTotalEarnings >= 1000)
    {
        std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
        std::cout << "On a roll!\n";
    }
    else if (aTotalEarnings < 0)
    {
        std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
        std::cout << "Sadge...\n";
    }
    else
    {
        std::cout << "\nTOTAL EARNINGS: " << aTotalEarnings << "kr\n";
        std::cout << "Keep gambling!!!\n";
    }
}

void WriteStat(int aPlace, int someStats[])
{
    if (someStats[aPlace] == 0)
    {
        std::cout << aPlace + 1 << ". " << "No stat" << std::endl;
    }
    else if (someStats[aPlace] == 1)
    {
        std::cout << aPlace + 1 << ". " << "Win" << std::endl;
    }
    else if (someStats[aPlace] == 2)
    {
        std::cout << aPlace + 1 << ". " << "Loss" << std::endl;
    }
}

void RollDice(Dice& aDie)
{
    std::uniform_int_distribution<int> rndDist(1, 6);

    aDie.one = rndDist(rndEngine);
    aDie.two = rndDist(rndEngine);
}

int DrawCard()
{
    std::uniform_int_distribution<int> rndDist(1, 11);
    return rndDist(rndEngine);
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

void PlayDiceGame(bool& gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[])
{
    int playerGuess = 0;
    static signed int totalEarnings = 0;
    bool diceGame = true;
	Dice die = {};

    while (diceGame)
    {
        if (!(diceGame = CheckIfBanned(totalEarnings)))
        {
            system("cls");
            std::cout << "\nYou earned too much at this table. Do something else.\n\n";
            system("pause");
            break;
        }
        else if (!(diceGame = GetGameMenu(3, totalEarnings, aPlayerWallet, aRewardMult)))
        {
            break;
        }

        aRewardMult = 2;

        ShowGameIntro(1, aPlayerWallet, aRewardMult);
        TotalEarningsMessage(totalEarnings);

        aBetAmount = GetPlayerBet(aBetAmount, aPlayerWallet, 1);

        system("cls");
        std::cout << "\nThe figure accepts your offer. \n";
        if (aBetAmount == aPlayerWallet)
        {
            std::cout << "\n***HIGH STAKES***\n";
            std::cout << "Betting your whole wallet increases your reward multiplier to X3.\n";
            aRewardMult = 3;
        }
        std::cout << "_______________________________ \n";


        std::cout << "What is your guess? (2-12)  ";
        playerGuess = GetPlayerNum(playerGuess, 12, 2);
        RollDice(die);

        system("cls");
        std::cout << "\nThe figure throws the dice dramatically...\n\n";
        std::cout << "Die 1: " << die.one << std::endl;
        std::cout << "Die 2: " << die.two << std::endl;
        std::cout << "Sum: " << die.one + die.two << std::endl;
        std::cout << "Your guess: " << playerGuess << std::endl;

        if (playerGuess == die.one + die.two)
        {
            std::cout << "\nThe figure winks and slips you something under the table.\n";
            std::cout << aBetAmount << "X" << aRewardMult << "kr added to wallet.\n";
            UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
            UpdateStatistics(1, someStats);
            totalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
            std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
            std::cout << "You are filled with determination.\n\n";
            system("pause");
            ShowStatistics(someStats);
        }
        else
        {
            UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
            std::cout << "\nYou watch as your " << aBetAmount << "kr dissappear under the table\n";
            std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
            totalEarnings -= aBetAmount;

            if (aPlayerWallet <= 0)
            {
                std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                system("pause");
                gameRunning = false;
                diceGame = false;
                break;
            }
            else
            {
                std::cout << "\nYou're having a bad time... Stay determined.\n\n\n";
                UpdateStatistics(2, someStats);
                system("pause");
                ShowStatistics(someStats);
            }
        }
    }
}

void PlayOddOrEven(bool& gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[])
{
    int playerGuess = 0;
    int rollResult = 0;
    static signed int totalEarnings = 0;
    bool oddOrEven = true;
    Dice die = {};
    
    aRewardMult = 2;

    while (oddOrEven)
    {
        if (!(oddOrEven = CheckIfBanned(totalEarnings)))
        {
            system("cls");
            std::cout << "\nYou earned too much at this table. Do something else.\n\n";
            system("pause");
            break;
        }
        else if (!(oddOrEven = GetGameMenu(3, totalEarnings, aPlayerWallet, aRewardMult)))
        {
            break;
        }

        ShowGameIntro(2, aPlayerWallet, aRewardMult);
        TotalEarningsMessage(totalEarnings);

        aBetAmount = GetPlayerBet(aBetAmount, aPlayerWallet, 1);

        system("cls");
        std::cout << "\nThe figure accepts your offer. \n";
        if (aBetAmount == aPlayerWallet)
        {
            std::cout << "\n***HIGH STAKES***\n";
            std::cout << "Betting your whole wallet fills you with determination.\n";
        }
        std::cout << "_______________________________ \n";


        std::cout << "\nTwo options. What is your bet?\n";
        std::cout << "1. Odd\n";
        std::cout << "2. Even\n";

        playerGuess = GetPlayerNum(playerGuess, 2, 1);
        RollDice(die);
        
        if (die.one % 2 == 0 && die.two % 2 == 0)
        {
            rollResult = 2;
        }
        else if (die.one % 2 != 0 && die.two % 2 != 0)
        {
            rollResult = 1;
        }
        else
        {
            rollResult = 0;
        }

        system("cls");
        std::cout << "\nThe figure throws the dice dramatically...\n\n";

        std::cout << "Die 1: " << die.one;
        if (die.one % 2 == 0)
        {
            std::cout << "  -> Even";
        }
        else
        {
            std::cout << "  -> Odd";
        }

        std::cout << "\nDie 2: " << die.two ;
        if (die.two % 2 == 0)
        {
            std::cout << "  -> Even";
        }
        else
        {
            std::cout << "  -> Odd";
        }

        std::cout << "\n\nYou guessed: ";
        if (playerGuess == 1)
        {
            std::cout << "Odd\n";
        }
        else
        {
            std::cout << "Even\n";
        }

        if (playerGuess == rollResult)
        {
            std::cout << "The figure nods slowly while handing over your reward.\n\n";
            std::cout << aBetAmount << "X" << aRewardMult << "kr added to wallet.\n";
            std::cout << "Reward multiplier increased by 1.\n";
            UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
            UpdateStatistics(1, someStats);
            totalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
            aRewardMult += 1;
            std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
            system("pause");
            ShowStatistics(someStats);
        }
        else
        {
            UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
            aRewardMult = 2;

            if (aPlayerWallet <= 0)
            {
                std::cout << "\nYou watch as your " << aBetAmount << "kr slip away from you...\n";
                std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                std::cout << "\nJust as you gambled away your last kr, you were suddenly dragged out of the casino. \nDetermination won't help you this time\n\n\n";
                system("pause");
                gameRunning = false;
                oddOrEven = false;
                break;
            }
            else
            {
                std::cout << "\nYou watch as your " << aBetAmount << "kr dissappear under the table\n";
                std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                UpdateStatistics(2, someStats);
                totalEarnings -= aBetAmount;
                std::cout << "\nYou're having a bad time... Stay determined.\n\n";
                system("pause");
                ShowStatistics(someStats);
            }
        }
    }
}

void PlayBlackjack(bool& gameRunning, int& aPlayerWallet, int aRewardMult, int aBetAmount, int someStats[])
{
    int hitOrStand = 0;
    int drawnCard = 0;
    int cardCount = 0;
    int cardSum = 0;
    static signed int totalEarnings = 0;
    bool blackjack = true;
    bool drawingCards = true;

    while (blackjack)
    {
        if (!(blackjack = CheckIfBanned(totalEarnings)))
        {
            system("cls");
            std::cout << "\nYou earned too much at this table. Do something else.\n\n";
            system("pause");
            break;
        }
        else if (!(blackjack = GetGameMenu(3, totalEarnings, aPlayerWallet, aRewardMult)))
        {
            break;
        }

        drawnCard = 0;
        cardCount = 1;
        cardSum = 0;
        drawingCards = true;
        aRewardMult = 1;

        ShowGameIntro(3, aPlayerWallet, aRewardMult);
        TotalEarningsMessage(totalEarnings);

        aBetAmount = GetPlayerBet(aBetAmount, aPlayerWallet, 1);

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

        drawnCard = DrawCard();
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
            hitOrStand = GetPlayerNum(hitOrStand, 2, 1);

            switch (hitOrStand)
            {
                case 1:
                {
                    drawnCard = DrawCard();
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
                        UpdatePlayerWallet(aBetAmount, aRewardMult, '-', aPlayerWallet);
                        UpdateStatistics(2, someStats);
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
                        ShowStatistics(someStats);
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
                case 2:
                {
                    system("cls");
                    std::cout << "Sum of cards: " << cardSum << std::endl;
                    std::cout << "Reward mult: X" << aRewardMult << std::endl;

                    if (aBetAmount == (aBetAmount * aRewardMult))
                    {
                        std::cout << "\nYou chose to stand and got your kr back. (counts as win)" << std::endl;
                        std::cout << "Balance: " << aPlayerWallet << "kr \n\n";
                        UpdateStatistics(1, someStats);
                    }
                    else
                    {
                        std::cout << "\nYou won " << aBetAmount * aRewardMult << "kr"  << std::endl;
                        UpdatePlayerWallet(aBetAmount, aRewardMult, '+', aPlayerWallet);
                        std::cout << "New balance: " << aPlayerWallet << "kr \n\n";
                        UpdateStatistics(1, someStats);
                    }
                    totalEarnings += (aBetAmount * aRewardMult) - aBetAmount;
                    system("pause");
                    ShowStatistics(someStats);
                    drawingCards = false;
                    break;
                }
                default:
                    break;
            }
        }
    }
}