#include<iostream>
#include "dna.h"
using std::min;

int factorial (int num)
{
    int i;
    int fact = 1;
    
    for(i=1;i<=num;i++)
    {
        fact = fact * i;
    }
    return fact;
    
}

int gcd (int num1, int num2)
{
    int result = min(num1, num2);
    while (result > 0)
    {
        if (num1 % result == 0 && num2 % result == 0)
        {
            break;
        }
        result --;
    }  

    return result;
}

