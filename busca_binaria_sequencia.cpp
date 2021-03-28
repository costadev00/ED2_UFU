//dupla: Matheus Costa e Edinéia
#include <bits/stdc++.h>
using namespace std;

int cont = 0;
int contb = 0;

int buscaSequencial(vector<int> arr, int n)
{
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i] == n)
        {
            return i;
        }
        cont++;
    }
    return -1;
}

int buscaBinaria(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
        {
            contb++;
            return m;
        }

        if (arr[m] > x)
        {
            contb++;
            return buscaBinaria(arr, l, m - 1, x);
        }

        contb++;
        return buscaBinaria(arr, m + 1, r, x);
    }

    return -1;
}

int main()
{
    FILE *arq;
    vector<int> arr;
    int n, num, res = -1;
    arq = fopen("entrada1.txt", "r");

    for (int i = 0; i < 1000; i++)
    {
        fscanf(arq, "%d ", &num);
        arr.push_back(num);
    }
    printf("Digite o numero a ser buscado: ");
    scanf("%d", &n);
    res = buscaSequencial(arr, n);
    if (res != -1)
    {
        printf("Numero de comparacoes na busca sequencial: %d\n", cont);
        printf("Foi encontrado na posicao(busca sequencial) : %d\n", res);
    }
    else
    {
        printf("Elemento nao encontrado\n");
        return 0;
    }

    sort(arr.begin(), arr.end());
    res = buscaBinaria(arr, 0, 1000, n);
    if (res != -1)
    {
        printf("Numero de comparacoes na busca binaria: %d\n", contb);
        printf("Foi encontrado na posicao(busca binaria) : %d\n", res);
    }
    return 0;
}