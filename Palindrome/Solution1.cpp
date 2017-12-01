/*
* Simple solution:
* Reverse the number into another by extracting one by one unit digit
*/
#include <iostream>

using namespace std;

int main ()
{
    int num, copy, digit, rev = 0;

    cout << "Enter the number: ";
    cin >> num;
    copy = num;

    // we reverse this variable named in rev
    while (num != 0)
    {
        digit = num % 10; // Extract unit digit
        rev = (rev * 10) + digit; // Append extracted digit to rev
        num = num / 10;
    }

    cout << "The reverse of the number is: " << rev << endl;

    if (rev == copy) // compares both numbers
    {
        cout << "The given number is a palindrome!\n";
    }
    else
    {
        cout << "The given number is not a palindrome!\n";
    }

    return 0;
}
