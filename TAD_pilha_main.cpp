/*

*/
#include <bits/stdc++.h>
using namespace std;
#include "TAD_pilha.cpp"

void binario(int n)
{
    int bin[8000];
    int aux;

    for (aux = 7; aux >= 0; aux--)
    {
        if (n % 2 == 0)
            bin[aux] = 0;
        else
            bin[aux] = 1;
        n = n / 2;
    }

    for (aux = 0; aux < 8; aux++)
        printf("%d", bin[aux]);

    printf("\n");
}
int main()
{
    int n, x;
    cout << "\nDigite -1 para remover um elemento da pilha, e converte-lo para binário\n";
    while (cin >> n)
    {
        if (n == -1)
        {
            x = p.top();
            binario(x);
            p.pop();
            continue;
        }
        p.push(n);
    }

    return 0;
}