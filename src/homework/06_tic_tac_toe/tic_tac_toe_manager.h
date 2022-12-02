#include <iostream>
#include "tic_tac_toe.h"
#include <memory>
#include <vector>
#include <string>

class TicTacToeManager
{
    public:
        friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
        void get_winner_totals(int& o, int& x, int& t);
        void save_game(std::unique_ptr<TicTacToe> &b);


    private:
        void update_winner_count(std::string);
        std::vector<std::unique_ptr<TicTacToe>> games;
        int o_wins = 0;
        int x_wins = 0;
        int tie = 0;
};