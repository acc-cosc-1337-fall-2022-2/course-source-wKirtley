//write include statement for decisions header
#include<iostream>
using std::cout; using std::endl;
char get_letter_grade_using_if(int grade)
{
    char letter_grade;

    if (grade < 0 || grade > 100)
    {
        cout << "Grade must be between 1 and 100." << endl;
        return 0;
    }
    else if (grade < 60)
    {
        letter_grade = 'F';
    }
    else if (grade < 70)
    {
        letter_grade = 'D';
    }
    else if (grade < 80)
    {
        letter_grade = 'C';
    }
    else if (grade < 90)
    {
        letter_grade = 'B';
    }
    else if (grade < 100)
    {
        letter_grade = 'A';
    }

    return letter_grade;
}

int get_letter_grade_using_switch(int grade)
{
    char letter_grade;

    switch(grade)
    {
        case 0 ... 59:
            letter_grade = 'F';
        break;

        case 60 ... 69:
            letter_grade = 'D';
        break;

        case 70 ... 79:
            letter_grade = 'C';
        break;

        case 80 ... 89:
            letter_grade = 'B';
        break;

        case 90 ... 100:
            letter_grade = 'A';
        break;
    }
    return letter_grade;
}
