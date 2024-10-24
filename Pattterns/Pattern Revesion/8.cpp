#include <iostream>
using namespace std;

int main()
{
    int n = 5; // Number of rows for the inverted pyramid

    for (int i = n; i >= 1; i--)
    {
        // Print spaces before the asterisks
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }

        // Print the asterisks for this row
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
