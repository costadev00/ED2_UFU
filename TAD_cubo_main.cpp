#include <bits/stdc++.h>
#include "TAD_cubo.cpp"
using namespace std;
int main()
{
    Cubo c1;
    int n, a;
    do
    {
        cout << "Digite a operacao:\n";
        cin >> n;

        switch (n)
        {
        case 1:
            printf("Digite o tamanho da aresta do cubo");
            cin >> a;
            c1.criar(a);
            break;
        case 2:
            c1.liberar();
            break;
        case 3:
            printf("O tamanho da aresta: %d\n", c1.acessar());
            break;
        case 4:
            printf("Digite o valor da aresta:\n");
            cin >> a;
            c1.alterar_aresta(a);
            break;
        case 5:
            printf("A area do lado: %d\n", c1.calcular_area_lado());
            break;
        case 6:
            printf("A area total: %d\n", c1.calcular_area_total());
            break;
        case 7:
            printf("Volume: %d\n", c1.calcular_volume());
            break;
        default:
            printf("Digite uma opcao valida\n");
            break;
        }
    } while (n != 0);
    return 0;
}