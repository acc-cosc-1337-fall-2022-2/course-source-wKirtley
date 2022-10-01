#include <iostream>
#include "dna.h"
using std::cout; using std::cin; using std::endl;

int main() 
{
	int choice;
	int num, num1, num2;
	int answer;
	char exit_input;

	do
	{
		cout << "Menu" << endl;
		cout << "(1) Factorial" << endl;
		cout << "(2) Greatest Common Divisor" << endl;
		cout << "(3) Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter a number: ";
			cin >> num;
			answer = factorial(num);
			cout << "Factorial: " << answer << endl;
		}

		else if (choice == 2)
		{
			cout << "Enter a number: "; cin >> num1;
			cout << "Enter another number: "; cin >> num2; 
			answer = gcd (num1, num2);
			cout << "The GCD of " << num1 << " and " << num2 << " is " << answer << endl;
		}
	}
	
	while (choice != 3);
	{	
		
		cout << "Are you sure you wish to exit? (y/n) ";
		cin >> exit_input;
		if (exit_input == 'y' || exit_input == 'Y')
		{
			return 0;
		}
		else if (exit_input == 'N' || exit_input == 'n')
		{
			main();
		}
	}	
	return 0;
}