#include <string>
#include <vector>
using namespace std;
using std::vector;
using std::string;
#ifndef TICTACTOE
#define TICTACTOE

class TicTacToe
{
    
    public:
        friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
        friend std::istream& operator>>(std::istream& in, TicTacToe& game);
        TicTacToe(){};
        TicTacToe(vector<string>p, string win){pegs=p; winner=win;}
        TicTacToe(int board_size):pegs(board_size*board_size, " "){};
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        //void display_board() const;
        string get_winner();
        vector<string> get_pegs()const{return pegs;}

    protected:
        vector<string> pegs;
        virtual bool check_row_win();
        virtual bool check_column_win();
        virtual bool check_diagonal_win();
        

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        string player;
        string winner;
};

#endif