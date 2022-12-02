#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <string>
#include <memory>
using std::string;
using  std::cin; using std::cout; using std::endl;


int main()
{
	int x_wins, o_wins, tie;
	string play_again;
	string player;
	std::unique_ptr<TicTacToe> game;
	TicTacToeManager manager;
	int game_size;
	LOOP: cout<<"Choose a game size of 3 or 4: ";
	cin>>game_size;
	if(game_size == 3){
		game=std::make_unique<TicTacToe3>();
	}
	else if (game_size == 4){
		game=std::make_unique<TicTacToe4>();
	}
	else{
		goto LOOP;
	}
	cout<<"Enter first player(X/O): ";
	cin>>player;
	if (player != "X" && player != "O")
	{
		cout<<"Player must either be X or O."<<endl;
		goto LOOP;
	}

	game->start_game(player);
	do{
		cout<<*game;
		cin>>*game;
		if (game->game_over()==true){
			string outcome = game->get_winner();
			cout<<outcome<<" wins."<<endl;
		}
	}
	while(game->game_over() == false); //saves winner correctly yet but board keeps going?? not sure.
	manager.save_game(game);
	cout<<"game over."<<endl;
	manager.get_winner_totals(o_wins, x_wins, tie);
	std::cout<<"X wins: "<<x_wins<<"  O wins: "<<o_wins<<"  Tied games: "<<tie<<endl;
	std::cout<<"Play again?(y/n): ";
	std::cin>>play_again;
	if(play_again=="y"){
		goto LOOP;
	}
	std::cout<<manager;
	
	int x_win;
	int o_win;
	int ties;
	manager.get_winner_totals( o_win,x_win,ties);
	std::cout<<"X wins: "<<x_win<<"  O wins: "<<o_win<<"  Tied games: "<<ties<<endl;
	return 0;

}