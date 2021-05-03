// C++ code to implement Fibonacci series
#include <bits/stdc++.h>
using namespace std;
// Function for fibonacci

int fib(int n)
{
    // Stop condition
    if (n == 0)
        return 0;

    // Stop condition
    if (n == 1 || n == 2)
        return 1;

    // Recursion function
    else
        return (fib(n - 1) + fib(n - 2));
}

// Driver Code
int main()
{
    // Initialize variable n.
    int n;
    while (cin >> n)
    {

        cout << "Fibonacci series of " << n << "numbers is: ";

        // for loop to print the fiboancci series.
        for (int i = 0; i < n; i++)
        {
            cout << fib(i) << " ";
        }
        cout << endl;
    }
    return 0;
}
