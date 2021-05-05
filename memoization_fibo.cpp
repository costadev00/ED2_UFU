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
#define FOR(i, a, b) for (int i = a; i < b; i++)

int lookup_fibo(int vet[], int n)
{
    if (vet[n] >= 0)
        return vet[n];
    if (n <= 1)
        vet[n] = n;
    else
        vet[n] = lookup_fibo(vet, n - 1) + lookup_fibo(vet, n - 2);
    return vet[n];
}
int memoized_fibo(int vet[], int n)
{
    for (int i = 0; i <= n; i++)
        vet[i] = -1;
    return lookup_fibo(vet, n);
}

int main()
{
    fastio;
    int n = 7;
    int vet[1000] = {-1};
    cout << memoized_fibo(vet, n);
    return 0;
}