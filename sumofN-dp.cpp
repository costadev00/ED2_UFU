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
#define MAXN 50000
// Given 3 numbers {1, 3, 5}, we need to tell
// the total number of ways we can form a number 'N'
// using the sum of the given three numbers.
// (allowing repetitions and different arrangements).

// initialize to -1
int dp[MAXN];

// this function returns the number of
// arrangements to form 'n'
int solve(int n)
{
    // base case
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    // checking if already calculated
    if (dp[n] != -1)
        return dp[n];

    // storing the result and returning
    return dp[n] = solve(n - 1) + solve(n - 3) + solve(n - 5);
}

int main()
{
    fastio;
    int n;
    cin >> n;
    do
    {
        FOR(i, 0, MAXN)
        dp[i] = -1;
        cout << solve(n) << endl;
    } while (cin >> n);
    return 0;
}