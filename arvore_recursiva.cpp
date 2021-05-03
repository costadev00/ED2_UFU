#include <bits/stdc++.h>
using namespace std;

int x = 0;

int asterisco(int n)
{
    if (n == 0)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ' ';
    }
    for (int i = 0; i <= x; i++)
    {
        printf("* ");
    }
    printf("\n");
    x++;
    return (asterisco(n - 1));
}

int main()
{
    int n;
    while (cin >> n)
    {
        x = 0;
        asterisco(n);
    }
    return 0;
}