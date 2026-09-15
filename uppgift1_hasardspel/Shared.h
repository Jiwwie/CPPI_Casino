#pragma once

namespace Shared
{
    enum GameResult
    {
	    GameResult_NoStat = 0,
	    GameResult_Win = 1,
	    GameResult_Loss = 2,
    };

    enum Game
    {
	    Game_DiceGame = 1,
	    Game_OddOrEven = 2,
	    Game_Blackjack = 3,
	    Game_RockPaperScissors = 4
    };

    void ShowMainMenu();

}