#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
using std::unique_ptr;
using std::make_unique;
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>();
	game->start_game("X");
	REQUIRE(game->get_player()=="X");
}

TEST_CASE("Test first player set to O")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>();
	game->start_game("O");
	REQUIRE(game->get_player()=="O");
}
TEST_CASE("Test game over if 9 slots are selected")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(9);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="C");
	
}
TEST_CASE("Test win by first column")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(1);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(2);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(4);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(5);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//7 for x
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by second column")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by third column")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(3);
	REQUIRE(game->game_over()==false);
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by first row")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by second row")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by third row")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win diagonally from top left")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win diagonally from bottom left")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); 
	game->start_game("X");
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test TicTacToe manager get winner total function")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe3>(); // tie game
	TicTacToe_manager manager;
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(9);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="C");//require c for "call it a tie". this set of potitions is a tie.
	manager.save_game(game);

	unique_ptr<TicTacToe> game1= make_unique<tic_tac_toe3>(); // x win 1
	game1->start_game("X");
	game1->mark_board(1);//1 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(2);//2 for o
	REQUIRE(game1->game_over()==false);
	game1->mark_board(4);//4 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(5);//5 for o
	REQUIRE(game1->game_over()==false);
	game1->mark_board(7);//7 for x
	REQUIRE(game1->game_over()==true);
	REQUIRE(game1->get_winner()=="X");
	manager.save_game(game1);


	unique_ptr<TicTacToe> game2= make_unique<tic_tac_toe3>(); // o first win
	game2->start_game("O");
	game2->mark_board(1);//1 for o
	REQUIRE(game2->game_over()==false);
	game2->mark_board(2);//2 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(4);//4 for o
	REQUIRE(game2->game_over()==false);
	game2->mark_board(5);//5 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(7);//7 for o
	REQUIRE(game2->game_over()==true);
	REQUIRE(game2->get_winner()=="O");
	manager.save_game(game2);


	unique_ptr<TicTacToe> game3= make_unique<tic_tac_toe3>(); //o second win
	game3->start_game("O");
	game3->mark_board(1);//1 for o
	REQUIRE(game3->game_over()==false);
	game3->mark_board(2);//2 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(4);//4 for o
	REQUIRE(game3->game_over()==false);
	game3->mark_board(5);//5 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(7);//7 for o
	REQUIRE(game3->game_over()==true);
	REQUIRE(game3->get_winner()=="O");
	manager.save_game(game3);


		unique_ptr<TicTacToe> game4= make_unique<tic_tac_toe3>(); //o third win
	game4->start_game("O");
	game4->mark_board(1);//1 for o
	REQUIRE(game4->game_over()==false);
	game4->mark_board(2);//2 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(4);//4 for o
	REQUIRE(game4->game_over()==false);
	game4->mark_board(5);//5 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(7);//7 for o
	REQUIRE(game4->game_over()==true);
	REQUIRE(game4->get_winner()=="O");
	manager.save_game(game4);



	
		unique_ptr<TicTacToe> game5= make_unique<tic_tac_toe3>(); //x second win
	game5->start_game("X");
	game5->mark_board(1);//1 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(2);//2 for o
	REQUIRE(game5->game_over()==false);
	game5->mark_board(4);//4 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(5);//5 for o
	REQUIRE(game5->game_over()==false);
	game5->mark_board(7);//7 for x
	REQUIRE(game5->game_over()==true);
	REQUIRE(game5->get_winner()=="X");
	manager.save_game(game5);

// 6 games played(0-5). 1 tie, 2 wins for X, 3 wins for O. 

	int x_win;
	int o_win;
	int ties;
	manager.get_winner_total( o_win,x_win,ties);
	REQUIRE(x_win==2);//let x win 2 time 
	REQUIRE(o_win==3); // let o win 3 time to differentiate tallies.
	REQUIRE(ties==1);//tie once
}



//-----------------------------Tests for Tic Tac Toe 4 below demarcation ------------------------------------------------------



TEST_CASE("Test first player set to X 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>();
	game->start_game("X");
	REQUIRE(game->get_player()=="X");
}

TEST_CASE("Test first player set to O 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>();
	game->start_game("O");
	REQUIRE(game->get_player()=="O");
}
TEST_CASE("Test game over if 9 slots are selected 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==false);
	game->mark_board(10);
	REQUIRE(game->game_over()==false);
		game->mark_board(9);
	REQUIRE(game->game_over()==false);
	game->mark_board(12);
	REQUIRE(game->game_over()==false);
	game->mark_board(11);
	REQUIRE(game->game_over()==false);
	game->mark_board(13);
	REQUIRE(game->game_over()==false);
	game->mark_board(14);
	REQUIRE(game->game_over()==false);
	game->mark_board(15);
	REQUIRE(game->game_over()==false);
	game->mark_board(16);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="C");
	
}
TEST_CASE("Test win by first column 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(1);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(2);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(5);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(6);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(9);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(13);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by second column 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(2);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(3);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(6);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(14);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by third column 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
		game->start_game("X");
	game->mark_board(3);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(4);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(8);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(12);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(15);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
		game->start_game("X");
	game->mark_board(4);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(3);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(8);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(12);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(16);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win by first row 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
		game->start_game("X");
	game->mark_board(1);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(5);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(2);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(6);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(3);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(4);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by second row 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
		game->start_game("X");
	game->mark_board(5);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(9);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(6);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(8);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by third row 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
		game->start_game("X");
	game->mark_board(9);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(13);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(14);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(15);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(12);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}
TEST_CASE("Test win by fourth row 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(13);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(9);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(14);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(15);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(16);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}


TEST_CASE("Test win diagonally from top left 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(1);//1 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(2);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(6);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(12);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(16);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test win diagonally from bottom left 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); 
	game->start_game("X");
	game->mark_board(13);//1 for x should be 13
	REQUIRE(game->game_over()==false);
	game->mark_board(14);//2 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(10);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(11);//5 for o
	REQUIRE(game->game_over()==false);
	game->mark_board(7);//7 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(8);//4 for x
	REQUIRE(game->game_over()==false);
	game->mark_board(4);//5 for o
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="X");
}

TEST_CASE("Test TicTacToe manager get winner total function 4")
{
	unique_ptr<TicTacToe> game = make_unique<tic_tac_toe4>(); // tie game
	TicTacToe_manager manager;
	game->start_game("X");
	game->mark_board(1);
	REQUIRE(game->game_over()==false);
	game->mark_board(2);
	REQUIRE(game->game_over()==false);
	game->mark_board(3);
	REQUIRE(game->game_over()==false);
	game->mark_board(4);
	REQUIRE(game->game_over()==false);
	game->mark_board(5);
	REQUIRE(game->game_over()==false);
	game->mark_board(6);
	REQUIRE(game->game_over()==false);
	game->mark_board(7);
	REQUIRE(game->game_over()==false);
	game->mark_board(8);
	REQUIRE(game->game_over()==false);
	game->mark_board(10);
	REQUIRE(game->game_over()==false);
		game->mark_board(9);
	REQUIRE(game->game_over()==false);
	game->mark_board(12);
	REQUIRE(game->game_over()==false);
	game->mark_board(11);
	REQUIRE(game->game_over()==false);
	game->mark_board(13);
	REQUIRE(game->game_over()==false);
	game->mark_board(14);
	REQUIRE(game->game_over()==false);
	game->mark_board(15);
	REQUIRE(game->game_over()==false);
	game->mark_board(16);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner()=="C");//require c for "call it a tie". this set of potitions is a tie.
	manager.save_game(game);

	unique_ptr<TicTacToe> game1= make_unique<tic_tac_toe4>(); // x win 1
	game1->start_game("X");
	game1->mark_board(9);//1 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(13);//2 for o
	REQUIRE(game1->game_over()==false);
	game1->mark_board(10);//4 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(14);//5 for o
	REQUIRE(game1->game_over()==false);
	game1->mark_board(11);//7 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(15);//4 for x
	REQUIRE(game1->game_over()==false);
	game1->mark_board(12);//5 for o
	REQUIRE(game1->game_over()==true);
	REQUIRE(game1->get_winner()=="X");
	manager.save_game(game1);


	unique_ptr<TicTacToe> game2= make_unique<tic_tac_toe4>(); // o first win
			game2->start_game("O");
	game2->mark_board(9);//1 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(13);//2 for o
	REQUIRE(game2->game_over()==false);
	game2->mark_board(10);//4 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(14);//5 for o
	REQUIRE(game2->game_over()==false);
	game2->mark_board(11);//7 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(15);//4 for x
	REQUIRE(game2->game_over()==false);
	game2->mark_board(12);//5 for o
	REQUIRE(game2->game_over()==true);
	REQUIRE(game2->get_winner()=="O");
	manager.save_game(game2);


	unique_ptr<TicTacToe> game3= make_unique<tic_tac_toe4>(); //o second win
game3->start_game("O");
	game3->mark_board(5);//1 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(9);//2 for o
	REQUIRE(game3->game_over()==false);
	game3->mark_board(6);//4 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(10);//5 for o
	REQUIRE(game3->game_over()==false);
	game3->mark_board(7);//7 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(11);//4 for x
	REQUIRE(game3->game_over()==false);
	game3->mark_board(8);//5 for o
	REQUIRE(game3->game_over()==true);
	REQUIRE(game3->get_winner()=="O");
	manager.save_game(game3);


		unique_ptr<TicTacToe> game4= make_unique<tic_tac_toe4>(); //o third win
	game4->start_game("O");
	game4->mark_board(1);//1 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(2);//2 for o
	REQUIRE(game4->game_over()==false);
	game4->mark_board(5);//4 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(6);//5 for o
	REQUIRE(game4->game_over()==false);
	game4->mark_board(9);//7 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(10);//4 for x
	REQUIRE(game4->game_over()==false);
	game4->mark_board(13);//5 for o
	REQUIRE(game4->game_over()==true);
	REQUIRE(game4->get_winner()=="O");
	manager.save_game(game4);



	
	unique_ptr<TicTacToe> game5= make_unique<tic_tac_toe4>(); //x second win
	game5->start_game("X");
	game5->mark_board(1);//1 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(2);//2 for o
	REQUIRE(game5->game_over()==false);
	game5->mark_board(5);//4 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(6);//5 for o
	REQUIRE(game5->game_over()==false);
	game5->mark_board(9);//7 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(10);//4 for x
	REQUIRE(game5->game_over()==false);
	game5->mark_board(13);//5 for o//should be 13
	REQUIRE(game5->game_over()==true);
	REQUIRE(game5->get_winner()=="X");
	manager.save_game(game5);

// 6 games played(0-5). 1 tie, 2 wins for X, 3 wins for O. 

	int x_win;
	int o_win;
	int ties;
	manager.get_winner_total( o_win,x_win,ties);
	REQUIRE(x_win==2);//let x win 2 time 
	REQUIRE(o_win==3); // let o win 3 time to differentiate tallies.
	REQUIRE(ties==1);//tie once
}