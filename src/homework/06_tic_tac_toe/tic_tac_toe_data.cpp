//cpp
#include <tic_tac_toe_3.h>
#include <tic_tac_toe_4.h>
#include <tic_tac_toe_data.h>
#include <tic_tac_toe.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <memory>
using std::vector; using std::string; using std::unique_ptr;

void TicTacToeData :: save_games(const std::vector<std::unique_ptr<TicTacToe>>&games)
{
    std::ofstream outputFile;
    outputFile.open("tic_tac_toe_file.txt");
    for(const auto &game:games)
    {
        vector<string> j = game->get_pegs();
        for(int i=0; i<j.size(); i++)
        {
            outputFile<<j[i];
        }
        outputFile<<game->get_winner();
        outputFile<<"\n";
    }
    outputFile.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData :: get_games()
{
    vector<unique_ptr<TicTacToe>> boards;
    std::ifstream inputFile;
    inputFile.open("tic_tac_toe_file.txt");
    string line;
    while (getline(inputFile,line))
    {
        vector<string> pegs;
        for(int i=0; i<(line.size()-1); i++)
        {
            char f = line[i];
            string x(1,f);
            pegs.push_back(x);
        }
        auto c=string(1,line[(line.size()-1)]);
        string winner = c;
        std::unique_ptr<TicTacToe> board;
        if (pegs.size()==9)
        {
            board = std::make_unique<tic_tac_toe3>(pegs, winner);
        }
        else if(pegs.size()==16)
        {
            board = std::make_unique<tic_tac_toe4>(pegs, winner);
        }
        boards.push_back(std::move(board));

    }
    inputFile.close();
    return boards;
}

