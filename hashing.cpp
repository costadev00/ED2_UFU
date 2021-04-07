#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define MOD 1000000007
#define MAX 10000000
#define vi vector<int>
#define pb push_back
#define FOR(i, a, b) for (int i = a; i < b; i++)

int vet[MAX] = {NULL};
void hash_insert(int x)
{
    int pos;
    pos = x % 10;
    vet[pos] = x;
}
int hash_search(int x)
{
    int pos = x % 10;
    return pos;
}
int main()
{
    string city = "abc";
    int x = city[0] + city[1] + city[2];
    cout << x;
    return 0;
}