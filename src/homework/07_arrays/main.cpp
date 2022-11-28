#include <iostream>
#include <vector>
#include <string>
using std::string; using std::vector;
using namespace std;

int main()
{
    bool val = true;
    vector<string> pegs = {"O", " ", " "};
    for (auto & elem : pegs){
        if (elem == "O" || elem == " "){
            val = false;
        }
        else{
            val = true;
        }
    }
    cout << val;
    return 0;

}