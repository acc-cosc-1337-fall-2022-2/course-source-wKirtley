#include <iostream>
#include "tic_tac_toe.h"
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::count;
using namespace std;


void TicTacToe :: start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        clear_board();
        display_board();
        player = first_player;
    }
    else
    {
        cout<<"Player must be either X or O: ";
        cin>>first_player;
        player = first_player;
    }
    
}

void TicTacToe :: display_board() const
{
    for (int i=0; i<3; i++)
    {
        if(i%3 == 2)
        {
            cout<<pegs[i];
        }
        else{
            cout<<pegs[i]+"|";
        }
      
    }
    cout<<endl;
    cout<<"-|-|-";
    cout<<endl;
    for (int i=3; i<6; i++)
    {
        if(i%3 == 2)
        {
            cout<<pegs[i];
        }
        else{
            cout<<pegs[i]+"|";
        }
    }
    cout<<endl;
    cout<<"-|-|-";
    cout<<endl;
    for (int i=6; i<9; i++)
    {
        if(i%3 == 2)
        {
            cout<<pegs[i];
        }
        else{
            cout<<pegs[i]+"|";
        }
    }
    cout<<endl;

}
void TicTacToe :: mark_board(int position)
{
    if (pegs[position] == " "){
        pegs[position] = player;
    }
    
}


void TicTacToe :: set_next_player()
{
    if (player == "X"){
        player = "O";
    }
    else{
        player = "X";
    }
}

bool TicTacToe :: check_board_full()
{
    string key = " ";
    if (count(pegs.begin(), pegs.end(), key)){
        return false;
    }
    else{
        return true;
    }

}

void TicTacToe :: clear_board()
{
    pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
}

bool TicTacToe :: game_over()
{
    if (check_column_win()){
        set_winner();
        return true;
    }
    if (check_row_win()){
        set_winner();
        return true;
    }
    if (check_diagonal_win()){
        set_winner();
        return true;
    }
    if (check_board_full()){
        return true;
    }
    return false;
}

bool TicTacToe :: check_row_win()
{
    bool val = false;
    if ((pegs[0]=="X"&&pegs[1]=="X"&&pegs[2]=="X")||
    (pegs[0]=="O"&&pegs[1]=="O"&&pegs[2]=="O")){
        val = true;
    }
    else if ((pegs[3]=="X"&&pegs[4]=="X"&&pegs[5]=="X")||
    (pegs[3]=="O"&&pegs[4]=="O"&&pegs[5]=="O")){
        val = true;
    }
    else if ((pegs[6]=="X"&&pegs[7]=="X"&&pegs[8]=="X")||
    (pegs[6]=="O"&&pegs[7]=="O"&&pegs[8]=="O")){
        val = true;
    }
    return val;
}

bool TicTacToe :: check_column_win()
{
    bool val = false;
    if ((pegs[0]=="X"&&pegs[3]=="X"&&pegs[6]=="X")||
    (pegs[0]=="O"&&pegs[3]=="O"&&pegs[6]=="O")){
        val = true;
    }
    else if ((pegs[1]=="X"&&pegs[4]=="X"&&pegs[7]=="X")||
    (pegs[1]=="O"&&pegs[4]=="O"&&pegs[7]=="O")){
        val = true;
    }
    else if ((pegs[2]=="O"&&pegs[5]=="O"&&pegs[8]=="O")||
    (pegs[2]=="X"&&pegs[5]=="X"&&pegs[8]=="X")){
        val = true;
    }
    return val;
}

bool TicTacToe :: check_diagonal_win()
{
    bool val = false;
    if ((pegs[0]=="X"&&pegs[4]=="X"&&pegs[8]=="X")||
    (pegs[0]=="O"&&pegs[4]=="O"&&pegs[8]=="O")){
        return true;
    }
    else if ((pegs[2]=="X"&&pegs[4]=="X"&&pegs[6]=="X")||
    (pegs[2]=="O"&&pegs[4]=="O"&&pegs[6]=="O")){
        return true;
    }
    return val;
}

void TicTacToe :: set_winner()
{
    if (player == "X"){
        winner = "O";
    }
    else{
        winner = "X";
    }
}

string TicTacToe :: get_winner()
{
    set_winner();
    return winner;
}

string TicTacToe :: get_player() const
{
    return player;
}
void TicTacToe :: get_clear_board()
{
    clear_board();
}

void TicTacToe :: get_set_player()
{
    set_next_player();
}