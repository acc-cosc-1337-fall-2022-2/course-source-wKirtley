#include <iostream>
#include "func.h"

using namespace std;
using std::string;



double get_gc_content(const string& dna)
{
    int i=0, count=0;
    for(i=0; i<dna.size(); i++)
    {
    if(dna[i] == 'G' || dna[i] == 'C')
    {
        count++;
    }
    }
    return ((double)count)/dna.size();

}

string reverse_string(string dna)
{
    string rstr = "";
    for(int i=dna.length()-1; i>=0; i--)
    {
        rstr += dna[i];
    }
    return rstr;
}

string get_dna_compliment(string dna)
{
    string compliment = "";
    dna = reverse_string(dna);
    for(int i=0; i<dna.length(); i++)
    {
        if(dna[i] == 'A')
        {
        compliment += 'T';
        }
        else if(dna[i] == 'T')
        {
        compliment += 'A';
        }
        else if(dna[i] == 'G')
        {
        compliment += 'C';
        }
        else if(dna[i] == 'C')
        {
        compliment += 'G';
        }
    }
    return compliment;
}

