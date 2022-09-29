//write include statements
#include "hwexpressions.h"
#include <iostream>

//write namespace using statement for cout
using std::cout;
using std::cin;
using std::endl;
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
double get_sales_tax_amount(double meal_amount);
double get_tip_amount(double meal_amount, double tip_rate);
int main()
{
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	cout << "Enter meal amount: ";
	cin >> meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);
	cout << "Enter tip rate: ";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);
	total = meal_amount + tax_amount + tip_amount;

	cout << "Meal Amount: " << meal_amount << endl;
	cout << "Sales Tax: " << tax_amount << endl;
	cout << "Tip Amount: " << tip_amount << endl;
	cout << "Total: " << total << endl;

	return 0;
	
}
