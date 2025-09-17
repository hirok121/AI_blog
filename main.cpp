#include <iostream>
#include <limits>

using namespace std;

// Function to add two numbers
double add(double a, double b);
double add(double a,double b){
    return a+b;
}

// Function to subtract two numbers
double sub(double a, double b);
double sub(double a,double b){
    return a-b;
}

// Function to multiply two numbers
double mul(double a, double b);
double mul(double a, double b){
    return a * b;
}

// Function to divide two numbers
double div(double a, double b);
double div(double a, double b){
    return a / b;
}

// Function to get a valid number from user input
double getNumber(const string &prompt)
{
    double number;
    cout << prompt;

    while (!(cin >> number))
    {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return number;
}

// Function to get user's choice
int getChoice()
{
    int choice;
    cout << "\nEnter your choice (0-4): ";

    while (!(cin >> choice) || choice < 0 || choice > 4)
    {
        cout << "Invalid input! Please enter a number between 0 and 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

int main()
{
    cout << "=== Simple Calculator ===" << endl;
    cout << "Available operations:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "0. Exit" << endl;
    cout << "=========================" << endl;

    while (true)
    {
        int choice = getChoice();

        if (choice == 0)
        {
            cout << "Thank you for using the calculator!" << endl;
            break;
        }

        double num1 = getNumber("Enter first number: ");
        double num2 = getNumber("Enter second number: ");
        double result;

        switch (choice)
        {
        case 1: // Addition
            result = add(num1, num2);
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;

        case 2: // Subtraction
            result = sub(num1, num2);
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;

        case 3: // Multiplication
            result = mul(num1, num2);
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;

        case 4: // Division
            if (num2 != 0)
            {
                result = div(num1, num2);
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            }
            else
            {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;

        default:
            cout << "Invalid operation!" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
