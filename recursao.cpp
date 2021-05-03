#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int buscaBinaria(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] > x)
        {
            return buscaBinaria(arr, l, m - 1, x);
        }

        return buscaBinaria(arr, m + 1, r, x);
    }

    return -1;
}

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int x = fibo(n - 1) + fibo(n - 2);
    return x;
}

int fat(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n * fat(n - 1);
}

int somatoria(int n)
{
    // int k = n;
    if (n == 0)
    {
        return 0;
    }
    // k--;
    return n + somatoria(n - 1);
}

int main()
{
    int n;
    vector<int> vet;
    cin >> n;
    cout << fibo(n) << endl;
    cout << fat(n) << endl;
    for (int i = 1; i <= n; i++)
    {
        vet.push_back(i * 7);
    }
    sort(vet.begin(), vet.end());
    cout << buscaBinaria(vet, 0, n, n + 1) << endl;
    cout << somatoria(n);
    return 0;
}