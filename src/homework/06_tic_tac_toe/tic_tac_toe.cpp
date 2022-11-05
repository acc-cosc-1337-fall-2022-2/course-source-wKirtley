#include <iostream>
#include "tic_tac_toe.h"
#include <string>
#include <vector>
using std::string;
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
    bool var = false;
    for (int i = 0; i < 9; i++)
    {
        if(pegs[i] == " ")
        {
            var += true;
        }
        else
        {
            var += false;
        }
    }
    return !var;
}

void TicTacToe :: clear_board()
{
    pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
}

bool TicTacToe :: game_over()
{
    return check_board_full();
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