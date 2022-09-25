//write include statements
#include<iostream>
#include "decisions.h"
using std::cout; using std::cin; using std::endl;
char get_letter_grade_using_if();
int main() 
{
	int grade;
	char letter_grade;
	int menu_option;

	cout << "Main Menu" << endl;
	cout << "(1) Letter Grade using if" << endl;
	cout << "(2) Letter Grade using switch" << endl;
	cout << "(3) Exit" << endl;
	cout << "Enter choice: ";
	cin >> menu_option;

	if (menu_option == 1)
	{
		cout << "Enter grade: ";
		cin >> grade;
		letter_grade = get_letter_grade_using_if(grade);
		cout << "Letter Grade: " << letter_grade << endl;
	}
	else if (menu_option == 2)
	{
		cout << "Enter grade: ";
		cin >> grade;
		letter_grade = get_letter_grade_using_switch(grade);
		cout << "Letter Grade: " << letter_grade << endl;
	}

	else if (menu_option == 3)
	{
		return 0;
	}

	return 0;
}