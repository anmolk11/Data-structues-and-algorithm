#include <iostream>
using namespace std;

void data_types()
{
    // Q1. Write a C++ program that declares a double variable and assigns it a value of 3.14. Print the value of the variable to the console.

    double d = 3.14;
    cout << "d = " << d << endl; // 3.14

    // Q2. Write a C++ program that declares a long integer variable and assigns it the value of the largest possible integer. Print the value of the variable to the console.

    long int li = 2147483647;
    cout << "li = " << li << endl; // 2147483647

    // Q3 Write a C++ program that declares a short integer variable and assigns it a value of 32767. Increment the variable by 1 and print the value of the variable to the console. Explain why the output is different than what was expected

    short int st = 32767;
    cout << "st = " << st << endl; // 32767
    st = st + 1;
    cout << "st = " << st << endl; // -32768

    // Explain why the output is different than what was expected
    // The output is different because the value of the variable is out of range of the short int data type. The value of the variable is 32768 which is out of range of the short int data type. The short int data type can only hold values from -32768 to 32767.

    // Check again now !!
    // st = st + 1;
    // cout << "st = " << st << endl; // -32767
}

void loops()
{
    // Q1. Write a C++ program that uses a while loop to print the numbers from 1 to 10 to the console.

    int i = 1;
    while (i <= 10)
    {
        cout << i << endl;
        i++;
    }

    // Q2. Write a C++ program that uses a do-while loop to ask the user to enter a number between 1 and 10 until they enter a valid number.

    int num;
    do
    {
        cout << "Enter a number between 1 and 10: ";
        cin >> num;
    } while (num < 1 || num > 10);

    // Q3. (Chocolate question) Write a C++ program that uses nested for loops to print a pyramid of asterisks to the console. The pyramid should have a height of 5.

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

double discriminant(double a, double b, double c)
{
    return (b * b) - (4 * a * c);
}

void greet(string name)
{
    cout << "Hello " << name << endl;
}

void functions()
{
    // auto greet = [](string name)
    // { cout << "Hello " << name << endl; };
    // Q1. Write a C++ program that defines a function called "greet" that takes a string parameter and prints a greeting message to the console.

    greet("John");

    // Q2. Write a C++ program that defines a function called "discriminant" that takes the value of a, b and c as parameters and calculate the discriminant of equation as per given formula. (here a,b,c are values as per equation ax+by+c = 0)

    double a, b, c;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    cout << "The discriminant is: " << discriminant(a, b, c) << endl;
}

int main()
{
    // data_types();
    // loops();
    functions();
    return 0;
}