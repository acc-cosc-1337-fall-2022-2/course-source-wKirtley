#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"

class tic_tac_toe3: public TicTacToe {
    
    public:
        tic_tac_toe3() : TicTacToe(3){}

    private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();

};

#endif