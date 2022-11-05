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
	cout<<"Enter first player: ";
	cin>>player;
	game.start_game(player);
	while (choice == "y"){
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
		game.get_clear_board();
		cout<<"Do you wish to continue?(y/n): ";
		cin>>choice;
	}
	cout<<"Game Over";
	return 0;
}