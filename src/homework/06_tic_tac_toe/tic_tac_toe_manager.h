#include <iostream>
#include <vector>
#include "tic_tac_toe.h"
#include <string>

#ifndef TICTACTOE_MANAGER_H
#define TICTACTOE_MANAGER_H

class TicTacToe_manager
{
    friend std::ostream& operator<<(ostream& out, const TicTacToe_manager& manager);
    public:
        void save_game(std::unique_ptr<TicTacToe>& game);
        void get_winner_total(int& o, int& w, int& t);
        std::vector<std::unique_ptr<TicTacToe>> games;

    private:
        int x_win = 0;
        int o_win = 0;
        int tie = 0;
        void update_winner_count(std::string winner);

};


#endif