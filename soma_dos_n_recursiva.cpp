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

int soma(int inicio, int fim)
{
    int m;
    m = fim / 2;
    if (inicio == fim)
    {
        return fim;
    }
    if (m < inicio)
        m = inicio;

    return soma(inicio, m) + soma(m + 1, fim);
}
int main()
{
    int n;
    cin >> n;
    cout << soma(0, n);
    return 0;
}