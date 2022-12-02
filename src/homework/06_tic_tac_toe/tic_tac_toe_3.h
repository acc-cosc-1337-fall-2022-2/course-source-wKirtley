#include "tic_tac_toe.h"
#include <iostream>
#ifndef TICTACTOE3_H
#define TICTACTOE3_H
class TicTacToe3 : public TicTacToe
{
    public:
        TicTacToe3() : TicTacToe(3){}
    
    private:
        bool check_row_win();
        bool check_column_win();
        bool check_diagonal_win();
};

#endif