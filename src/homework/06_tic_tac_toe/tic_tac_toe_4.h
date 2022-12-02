#include "tic_tac_toe.h"
#include <iostream>
#ifndef TICTACTOE4_H
#define TICTACTOE4_H
class TicTacToe4 : public TicTacToe
{
    public:
        TicTacToe4() : TicTacToe(4){}
    private:
        bool check_row_win();
        bool check_column_win();
        bool check_diagonal_win();
};

#endif