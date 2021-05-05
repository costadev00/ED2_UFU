// Implementar o problema da Mochila binária (0-1) utilizando as abordagens:
// a) PD top-down com memoização.
// b) PD bottom-up.

// Testar com os valores: peso = { 4, 2, 1, 3 } e valor = { 500, 400, 300, 450 } e responda qual é o valor máximo para uma mochila de peso W = 5.

// Entregar um arquivo compactado com o código-fonte. Pode ser feito em duplas (não se esqueçam de incluir os nomes dentro do código-fonte).
#include <bits/stdc++.h>
using namespace std;
int knapSackBottomUp(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

// Returns the value of maximum profit
int knapSackRec(int W, int wt[],
                int val[], int i,
                int **dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)
    {

        // Store the value of function call
        // stack in the table before return
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else
    {
        // Store value in a table before return
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));

        // Return value of table after storing
        return dp[i][W];
    }
}

int knapSackTopDown(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int **dp;
    dp = new int *[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    //memoization with -1 before calling the recursive function
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}
int main()
{
    int values[] = {500, 400, 300, 450};
    int weight[] = {4, 2, 1, 3};
    int W = 5;
    int n = sizeof(values) / sizeof(values[0]);
    cout << knapSackBottomUp(W, weight, values, n) << endl;
    cout << knapSackTopDown(W, weight, values, n) << endl;
    return 0;
}