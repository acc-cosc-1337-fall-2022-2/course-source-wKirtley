#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>
using std::string;
using std::unique_ptr;
using std::make_unique;
using namespace std;

int main() 
{
	unique_ptr<TicTacToe> game;
	string player;
	bool loop_again;
	TicTacToe_manager manager;
	int size;
	int x_wins;
	int o_wins;
	int ties;

	do {
		do {
			cout << "Do you want to play with a board of size 3 or 4: ";
			cin >> size;
			
			if (size == 3) {
				game = make_unique <tic_tac_toe3>();
			} else if (size == 4) {
				game = make_unique <tic_tac_toe4>();
			} else {
				cout << "Invalid size" << "\n";
			}

		} while(size != 3 && size != 4);


		cout << "Enter X or O: ";
		cin >> player;

		while (player != "X" && player != "O") {
			cout << "Invalid input try again" << "\n";
			cout << "Enter X or O: ";
			cin >> player;
		}

		game->start_game(player);

		do {
			cout << *game;
			cin >> *game;

		} while(game->game_over() == false);
		cout << *game;

		cout << "The winner is " << game->get_winner() << "\n";
		manager.save_game(game);
		manager.get_winner_total(o_wins, x_wins, ties);
		cout << "X has won " << x_wins << ". O has won " << o_wins << ". There has been " << ties << " ties." << "\n";

		cout << "Do you want to play again (1-yes 2-no): ";
		cin >> loop_again;

	} while (loop_again);

	cout << "\n" << "All games played:" << "\n";
	cout << manager;


	return 0;
}