#include <iostream>
#include "tic_tac_toe.h"
#include <string>

using namespace std;

void TicTacToe :: start_game(std::string player)
{
    clear_board();
    display_board();
    cout << "Your turn player " << player << ": ";
    cin >> position;
    mark_board(position);
}

void TicTacToe :: display_board() const
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            cout << " | ";
        }
        cout << pegs[i];
        if (i == 2 || i == 5)
        {
            cout << endl;
            cout << "--|---|--" << endl;
        }
    }
    cout << endl;
}

void TicTacToe :: clear_board()
{
    pegs[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

void TicTacToe :: mark_board(int position)
{
    if (pegs[position] == " ")
    {
        pegs[position] = player;
    }
    display_board();
    set_next_player();
}

std::string TicTacToe :: get_player() const
{
    return player;
}

void TicTacToe :: set_next_player()
{
    if (player == "X")
    {
        player == "O";
    }
    else
    {
        player == "X";
    }

}

bool TicTacToe :: check_board_full()
{
    for (int i = 0; i < 9; i++)
    {
        if (pegs[i] == " ")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}