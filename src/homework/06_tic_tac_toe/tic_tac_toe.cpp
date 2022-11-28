#include <iostream>
#include "tic_tac_toe.h"
#include <string>
#include <vector>
using std::string;
using namespace std;


void TicTacToe :: start_game(string first_player)
{
    player = first_player;
    winner = " ";
    clear_board();
}

void TicTacToe :: mark_board(int position)
{
    if (pegs[position] == " "){
        pegs[position] = player;
    }
    set_next_player();
    
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
    bool space=true;
    for(int i=0; i<pegs.size();i++)
            if(TicTacToe::pegs[i]==" ")
                space=false;
    return space;
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
    if ((check_board_full()==true)&&(check_column_win()==false&&check_row_win()==false&&check_diagonal_win()==false)){
        winner = "C";
        return true;
    }
    return false;
}

bool TicTacToe :: check_row_win()
{
    return false;
}

bool TicTacToe :: check_column_win()
{
    return false;
}

bool TicTacToe :: check_diagonal_win()
{
    return false;
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
    if (winner == "C"){
        return winner;
    }
    else{
        set_winner();
        return winner;
    }
    
}

string TicTacToe :: get_player() const
{
    return player;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {

    if (game.pegs.size()==9)
    {
        for(int i=0; i<9; i++)
        {   
            if (i==3||i==6)
            {
            std::cout<<"\n";
            }
        cout<<game.pegs[i];
        if(i!=2&&i!=5&&i!=8){
          std::cout<<"|";
            }
        }
    }
    else
    {
        for(int i=0; i<16; i++)
        {   
        if (i==4||i==8||i==12)
            {
                std::cout<<"\n";
            }
            cout<<game.pegs[i];
            if(i!=3&&i!=7&&i!=11&&i!=15)
            {
            std::cout<<"|";
            }
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    Position_Loop:int position;
    if (game.pegs.size()==9)
    {
        cout<<"\n Choose a position on the board(1-9): ";
		cin>>position;
		cin.clear();
		cin.sync();
    
		if (position!=1 && position!=2 && position!=3 && position!=4 && position!=5 && position!=6 && position!=7 && position!=8 && position!=9)
		{
			cout<<"\nPlease enter a number to play(1-9)\n";
			goto Position_Loop;
		}
	    if ((game.pegs[(position-1)])=="X"||(game.pegs[(position-1)]=="O"))
			{
				cout<<"You can't play that position.";
				goto Position_Loop;
			}
		game.mark_board(position);
    }
    else
    { 
        cout<<"\n What position do you wish to play?(1-16):\t";
		cin>>position;
		cin.clear();
		cin.sync();
        if (position!=1 && position!=2 && position!=3 && position!=4 && position!=5 && position!=6 && position!=7 && position!=8 && position!=9&& position!=10 && position!=11 && position!=12 && position!=13 && position!=14 && position!=15 && position!=16)
		    {
      		    cout<<"\nPlease enter a number to play(1-16)\n";
			    goto Position_Loop;
		    }
	    if ((game.pegs[(position-1)])=="X"||(game.pegs[(position-1)]=="O"))
			{
				cout<<"You can't play that position";
				goto Position_Loop;
			}
		game.mark_board(position);
    }
    return in;
}

