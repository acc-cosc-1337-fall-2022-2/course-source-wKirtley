#include <string>
#ifndef TICTACTOE
#define TICTACTOE

class TicTacToe
{
    public:
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        std::string get_player() const;
        void display_board() const;
    
    private:
        std::string player = "X";
        void set_next_player();
        bool check_board_full();
        void clear_board();
        std::string pegs[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
        int position;
        
};

#endif