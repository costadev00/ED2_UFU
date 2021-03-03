/*

*/
#include <bits/stdc++.h>
using namespace std;
class Cubo
{
public:
    int aresta;
    Cubo()
    {
        aresta = 0;
    }
    void criar(int p_aresta)
    {
        aresta = p_aresta;
    }
    void liberar()
    {
        aresta = NULL;
    }
    int acessar()
    {
        return aresta;
    }
    void alterar_aresta(int a)
    {
        aresta = a;
    }
    int calcular_area_lado()
    {
        return 4 * (aresta * aresta);
    }
    int calcular_area_total()
    {
        return 6 * (aresta * aresta);
    }
    int calcular_volume()
    {
        return pow(aresta, 3);
    }
};