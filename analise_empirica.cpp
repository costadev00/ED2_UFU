#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    FILE *arq;
    int maior = 0;
    clock_t inicio, fim;
    double time_spent;

    arq = fopen("entrada1.txt", "r");
    inicio = clock();
    for (int i = 0; i < 1000; i++)
    {
        fscanf(arq, "%d ", &num);
        if (maior < num)
        {
            maior = num;
        }
    }
    fim = clock();
    time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Time taken to find the largest element in array of 1000 random elements: - "
         << time_spent << " and the element is " << maior << endl;

    arq = fopen("entrada2.txt", "r");
    maior = 0;
    inicio = clock();
    for (int i = 0; i < 500000; i++)
    {
        fscanf(arq, "%d ", &num);
        if (maior < num)
        {
            maior = num;
        }
    }
    fim = clock();
    time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Time taken to find the largest element in array of 500000 random elements: - "
         << time_spent << " and the element is " << maior << endl;

    arq = fopen("entrada3.txt", "r");
    maior = 0;
    inicio = clock();
    for (int i = 0; i < 1000000; i++)
    {
        fscanf(arq, "%d ", &num);
        if (maior < num)
        {
            maior = num;
        }
    }
    fim = clock();
    time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Time taken to find the largest element in array of 1000000 random elements: - "
         << time_spent << " and the element is " << maior << endl;

    arq = fopen("entrada4.txt", "r");
    maior = 0;
    inicio = clock();
    for (int i = 0; i < 10000000; i++)
    {
        fscanf(arq, "%d ", &num);
        if (maior < num)
        {
            maior = num;
        }
    }
    fim = clock();
    time_spent = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Time taken to find the largest element in array of 10000000 random elements: - "
         << time_spent << " and the element is " << maior << endl;

    return 0;
}