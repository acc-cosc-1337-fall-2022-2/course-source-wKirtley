#include "tic_tac_toe.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

int main() 
{
	string player;
	TicTacToe game;
	cout<<"Enter first player: ";
	cin>>player;
	game.start_game(player);
	return 0;
}