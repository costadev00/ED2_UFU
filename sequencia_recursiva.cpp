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

vi vet;
int cont = 0;
int gensequence(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return 4 + gensequence(n - 1);
}
int main()
{
    fastio;
    int n;
    cin >> n;
    cout << gensequence(n) << endl;

    return 0;
}