#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <memory>

#ifndef TICTACTOEDATA_H
#define TICTACTOEDATA_H
class TicTacToeData
{
    public:
        void save_games(const std::vector<std::unique_ptr<TicTacToe>>&games);
        std::vector<std::unique_ptr<TicTacToe>>get_games();
};

#endif
