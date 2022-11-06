#include <iostream>
#include "func.h"
#include <cmath>
using namespace std;
using std::string;

int main() 
{
	int choice;
	double gc, percent;
	string compliment, dna;

	do{
		cout << "Main Menu" << endl;
		cout << "(1) Get GC Compliment" << endl;
		cout << "(2) Get DNA Compliment" << endl;
		cout << "(3) Exit" << endl;
		cout << "" << endl; cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1){
			cout << "Enter DNA string: ";
			cin >> dna;
			gc = get_gc_content(dna);
			percent = ceil(gc * 100);
			cout << "The GC content of that string is " << gc << " or roughly " << percent << "%." << endl; cout << "" << endl;
		}
		else if (choice == 2){
			cout << "Enter DNA string: ";
			cin >> dna;
			compliment = get_dna_compliment(dna);
			cout << "The compliment for that DNA string is " << compliment << "." << endl; cout << "" << endl;
		}
	}
	while (choice != 3);{
		cout << "Program exit." << endl;
	}
	return 0;
}