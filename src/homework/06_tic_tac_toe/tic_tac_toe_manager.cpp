#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include <iostream>
#include <memory>

void TicTacToeManager :: update_winner_count(std::string winner)
{
    if(winner == "X"){
        x_wins++;
    }
    if(winner == "O"){
        o_wins++;
    }
    else if(winner == "C"){
        tie++;
    }
}

void TicTacToeManager :: save_game(std::unique_ptr<TicTacToe>& b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}

void TicTacToeManager :: get_winner_totals(int& o, int& x, int& t)
{
    o = o_wins;
    x = x_wins;
    t = tie;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for (int i = 0; i <manager.games.size();i++)
        {
            out<<"\n"<<*(manager.games[i])<<"\n";
        } 
    
    return out;
}