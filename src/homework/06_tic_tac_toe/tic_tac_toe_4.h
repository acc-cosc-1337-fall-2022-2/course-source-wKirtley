#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"

class tic_tac_toe4: public TicTacToe {
    
    public:
        tic_tac_toe4() : TicTacToe(4){}

    private:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();

};

#endif