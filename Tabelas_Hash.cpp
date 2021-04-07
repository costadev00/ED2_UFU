#include <bits/stdc++.h>

using namespace std;

// int hash_insert(int x, int m, int vet[][])
// {
//     int pos = x % m;
//     return pos;
// }
int main()
{
    int n, m, c, x, k = 0;
    cin >> n;
    while (n--)
    {
        cin >> m >> c;
        // int vet[m][m] = {-1};
        vector<vector<int>> vet(m);
        for (int i = 0; i < c; i++)
        {
            cin >> x;
            int pos = x % m;
            vet[pos].push_back(x);
            // int pos = hash_insert(x, m, vet);
            // vet[pos] = x;
        }
        int i = 0;
        while (m--)
        {
            cout << i << " -> ";
            for (int j = 0; j < vet[i].size(); j++)
            {
                cout << vet[i][j] << " -> ";
            }
            i++;
            cout << "\\" << endl;
        }
        cout << endl;
    }
    if (n)
    {
        cout << endl;
    }

    return 0;
}