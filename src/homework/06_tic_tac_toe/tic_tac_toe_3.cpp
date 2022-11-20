#include "tic_tac_toe_3.h"
#include <string>
using std::string;

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

bool tic_tac_toe3::check_column_win() {
    bool val = false; 
    string previous_player;

    if (player == "X")
    {
        previous_player = "O";
    } 
    else if (player == "O") 
    {
        previous_player = "X";
    }

    for (int coulmn = 0; coulmn < 3 && win == 0; coulmn++) 
    {
        val = true;
        for (int row = 0; row < 3; row++) {

            if (pegs.at(coulmn + (row * 3 )) != previous_player)
            {
                val = false;
            }
        }
    }
    return val;
}

/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/

bool tic_tac_toe3::check_row_win() 
{
    bool val = false;
    string previous_player;

    if (player == "X")
    {
        previous_player = "O";
    } 
    else if (player == "O") 
    {
        previous_player = "X";
    }

    for (int row = 0; row < 3 && win == 0; row++) 
    {
        val = true;
        for (int coulmn = 0; coulmn < 3; coulmn++) 
        {

            if (pegs.at(coulmn + (row * 3 )) != previous_player )
            {
                val = false;
            }
        }
    }
    return val;
}

/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8
*/

bool tic_tac_toe3::check_diagonal_win() 
{
    bool val = false;
    string previous_player;

    if (player == "X")
    {
        previous_player = "O";
    } 
    else if (player == "O") 
    {
        previous_player = "X";
    }
   
    if (pegs.at(0) == previous_player && pegs.at(4) == previous_player && pegs.at(8) == previous_player) 
    {
        val = true;
    } 
    else if (pegs.at(2) == previous_player && pegs.at(4) == previous_player && pegs.at(6) == previous_player) 
    {
        val = true;
    } 
    else 
    {
        val = false;
    }

    return val;
}