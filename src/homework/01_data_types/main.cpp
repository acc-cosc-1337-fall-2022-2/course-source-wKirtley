//write include statements
#include "data_types.h"
#include <iostream>
//write namespace using statement for cout
using std::cout;
using std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int multiply_numbers(int num1);
int main()
{
	int num1;
	int result;
	cout<<"Enter value for num1: ";
	cin>>num1;
	result = multiply_numbers(num1);
	cout<<"product: "<<result;
	return 0;
}
