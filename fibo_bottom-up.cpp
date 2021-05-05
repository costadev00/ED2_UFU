#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define read(st) getline(cin, st)
#define sort stable_sort
#define FOR(i, a, b) for (int i = a; i < b; i++)

// int vet[10000];
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int vet[n];
    vet[0] = 0;
    vet[1] = 1;
    for (int i = 2; i <= n; i++)
        vet[i] = (vet[i - 1] + vet[i - 2]);
    return vet[n];
}
int main()
{
    fastio;
    cout << fibo(7);
    return 0;
}