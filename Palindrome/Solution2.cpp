/*
* Alternative solution:
* We convert number into string of characters and then compare characters.
* This solution doesn't involve multiplication and add operation to create rev.
* Is this solution more optimized than Solution1?
*/

#include <iostream>

using namespace std;

int main ()
{
    int num, digit, char_count = 0;
    char num_char[16];

    cout << "Enter the number: ";
    cin >> num;

    // we convert this num in char string
    while (num != 0)
    {
        digit = num % 10; // Extract unit digit
        num_char[char_count] = digit; // Add to num_char
        num = num / 10;
        char_count++;
    }

    for (int i = 0; i < char_count / 2; i++)
    {
        if (num_char[i] != num_char[char_count - i - 1])
        {
            cout << "The given number is not a palindrome!\n";
            return 0;
        }
    }

    cout << "The given number is a palindrome!\n";
    return 0;
}
