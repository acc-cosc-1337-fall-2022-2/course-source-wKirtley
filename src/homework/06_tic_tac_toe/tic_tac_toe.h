#include <string>
#include <memory>
#ifndef TICTACTOE
#define TICTACTOE
#include <vector>
using namespace std;
using std::vector;
using std::string;

class TicTacToe
{
    public:
        friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
        friend std::istream& operator>>(std::istream& in, TicTacToe& game);

        TicTacToe(){}
        TicTacToe(int size):pegs(size*size, " "){}
        bool game_over();
        void start_game(std::string first_player);
        void mark_board(int position);
        string get_player() const;
        void get_clear_board();
        void get_set_player();
        string get_winner();
    
    protected:
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        vector<string> pegs;

    private:
        string player;
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        string winner;

        
};

#endif