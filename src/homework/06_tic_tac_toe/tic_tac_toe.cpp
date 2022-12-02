#include <iostream>
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe.h"
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using std::string; using std::count;
using namespace std;


void TicTacToe :: start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        clear_board();
        player = first_player;
    }
    else
    {
        cout<<"Player must be either X or O: ";
        cin>>first_player;
        player = first_player;
    }
    
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if (game.pegs.size()==9){
    for (int i=0; i<3; i++)
    {
        if(i%3 == 2)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
      
    }
    out<<endl;
    out<<"-|-|-";
    out<<endl;
    for (int i=3; i<6; i++)
    {
        if(i%3 == 2)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
    }
    out<<endl;
    out<<"-|-|-";
    out<<endl;
    for (int i=6; i<9; i++)
    {
        if(i%3 == 2)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
    }
    out<<endl;
    }

    else{
        for (int i=0; i<4; i++)
    {
        if(i%4 == 3)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
      
    }
    out<<endl;
    out<<"-|-|-|-";
    out<<endl;
    for (int i=4; i<8; i++)
    {
        if(i%4 == 3)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
    }
    out<<endl;
    out<<"-|-|-|-";
    out<<endl;
    for (int i=8; i<12; i++)
    {
        if(i%4 == 3)
        {
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
    }
    out<<endl;
    out<<"-|-|-|-";
    out<<endl;
    for (int i=12; i<16; i++)
    {
        if (i%4 == 3){
            out<<game.pegs[i];
        }
        else{
            out<<game.pegs[i]+"|";
        }
    }
    out<<endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    if (game.pegs.size()==9)
    {
        cout<<"Choose a position(1-9): ";
		in>>position;
		game.mark_board(position-1);
        game.set_next_player();
    }
    else
    { 
        cout<<"Enter position(1-16): ";
		in>>position;
		game.mark_board(position-1);
        game.set_next_player();
    }
    

      return in;
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
    bool empty=true;
    for(int i=0; i<pegs.size();i++)
            if(TicTacToe::pegs[i]==" ")
                empty=false;
    return empty;

}

void TicTacToe :: clear_board()
{
    for(int i=0; i<9;i++){
        (TicTacToe::pegs[i])=" ";
    }
}


bool TicTacToe :: game_over()
{
    bool val = false;
    if ( check_column_win()==true|| check_row_win()==true||check_diagonal_win()==true)
    {
        set_winner();
        val= true;
    }
    else if(check_board_full()==true)
    {
        winner="C";
        val= true;
    }
    else if (check_board_full()!=true)
        val= false;
    return val;
}

bool TicTacToe::check_column_win()
{
 return false;
}

bool TicTacToe::check_row_win()
{
  return false;
}
bool TicTacToe::check_diagonal_win()
{
return false;
}

void TicTacToe :: set_winner()
{
    if (player == "X"){
        winner = "O";
    }
    else if(player == "O"){
        winner = "X";
    }
    else{
        winner = "C";
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