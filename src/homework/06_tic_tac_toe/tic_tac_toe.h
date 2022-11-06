#include <string>
#ifndef TICTACTOE
#define TICTACTOE
#include <vector>
using namespace std;
using std::vector;
using std::string;

class TicTacToe
{
    public:
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        string get_player() const;
        void display_board() const;
        void get_clear_board();
        void get_set_player();
        string get_winner();
    
    private:
        string player;
        void set_next_player();
        bool check_board_full();
        void clear_board();
        vector<string> pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();
        string winner;

        
};

#endif