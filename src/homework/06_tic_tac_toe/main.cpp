#include "tic_tac_toe.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

int main() 
{
	string player;
	int position;
	string choice = "y";
	TicTacToe game;
	while (choice == "y"){
		cout<<"Enter first player: ";
		cin>>player;
		game.start_game(player);
		while (game.game_over() == false)
		{
			cout<<"Player "<<player<<" choose a position on the board(1-9): ";
			cin>>position;
			game.mark_board(position-1);
			game.display_board();
			game.get_set_player();
			if (player == "X")
			{
				player = "O";
			}
			else{
				player = "X";
			}
		}
		player = game.get_winner();
		if (player  == "C"){
			cout<<"The game has ended in a tie."<<endl;
		}
		else{
			cout<<"The winner is player "<<player<<endl;
		}
		game.get_clear_board();
		cout<<"Do you wish to continue?(y/n): ";
		cin>>choice;
		game.get_set_player();
		
	}
	cout<<"Game Over."<<endl;
	return 0;
}