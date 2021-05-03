#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

//funcao recursiva
double form(double n)
{
    if (n == 1) 
    {
        return 2;
    }
    return 2 * form(n - 1);
}
int main()
{
    fastio;
    double n;
    cin >> n;

    cout << form(n) << endl;

    //formula fechada
    cout << pow(2, n);

    return 0;
}