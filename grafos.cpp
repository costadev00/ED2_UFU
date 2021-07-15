/*

*/
#include <bits/stdc++.h>

using namespace std;

class Grafo
{
private:
    // numero de vertices no grafo
    int n;

    // a matriz
    int g[10][10];

public:
    // CONSTRUTOR SUBSTITUINDO A FUNCAO inicializarGrafo(G) requisitada
    Grafo(int x)
    {
        n = x;

        //inicializando a matriz
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                g[i][j] = 0;
            }
        }
    }
    void imprime_matriz()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << "\n";
            for (int j = 0; j < n; ++j)
            {
                cout << " " << g[i][j];
            }
        }
    }
    void adicionarAresta(int v, int w)
    {

        // verifica se o vertices v e w existem no grafo/matriz
        if ((v >= n) || (w > n))
        {
            cout << "Vertice nao existe";
        }

        // vertifica se é um laço
        if (v == w)
        {
            cout << "Laço";
        }
        else
        {
            // cria a aresta
            g[w][v] = 1;
            g[v][w] = 1;
        }
    }

    //criamos uma nova linha e coluna na matriz, e como ele é somente um vertice ele nao tem nenhum tipo de conexao/aresta com os outros vertices
    void adicionarVertice()
    {
        // aumentamos o numero de vertices
        n++;
        int i;

        for (i = 0; i < n; ++i)
        {
            g[i][n - 1] = 0;
            g[n - 1][i] = 0;
        }
    }

    void removerVertice(int v)
    {
        // verifica se v esta presente no grafo
        if (v > n)
        {
            cout << "\nEsse vertice nao existe!";
            return;
        }
        else
        {
            int i;

            // removendo o vertice
            while (v < n)
            {
                for (i = 0; i < n; ++i)
                {
                    g[i][v] = g[i][v + 1];
                }

                for (i = 0; i < n; ++i)
                {
                    g[v][i] = g[v + 1][i];
                }
                v++;
            }

            // diminuindo os vertices na matriz
            n--;
        }
    }

    void bfs(int start)
    {
        //é criado um vertice visitado, dessa forma nenhum vertice é visitado mais de uma vez

        //esse vector é inicializado como falso, já que no início nenhum vértice foi visitado
        vector<bool> visited(n, false);
        //fila que vai fazer o controle da busca
        vector<int> q;
        // insere-se o elemento de partida na fila
        q.push_back(start);

        // elemento de partida é maracado como visitado
        visited[start] = true;

        int vis;
        while (!q.empty())
        {
            vis = q[0];

            // imprime o vertice atual
            cout << vis << " ";
            //remove o nó da fila após ter buscado todos os seus nós adjacentes
            q.erase(q.begin());

            // percorre todos os vertices adjacentes ao vertice atual
            for (int i = 0; i < n; i++)
            {
                if (g[vis][i] == 1 && (!visited[i]))
                {

                    // insere-se o nó adjascente na fila
                    q.push_back(i);

                    //marca-se o vertice como visitado
                    visited[i] = true;
                }
            }
        }
    }
    void dfs(int start, vector<bool> &visited)
    {
        // imprime o vertice atual
        cout << start << " ";

        // vertice atual = visitado
        visited[start] = true;

        for (int i = 0; i < n; i++)
        {
            // se algum vertice for adjacente ao vertice atual e ainda nao foi visitado
            if (g[start][i] == 1 && (!visited[i]))
            {
                //percorre o vertice adjacente, e todos os seus outros adjacente
                dfs(i, visited);
            }
        }
    }
};

int main()
{
    // criando um objeto da classe grafo, com a matriz de tamanho inicial de 10
    int n = 10;
    Grafo g(n);
    //vetor booleano para ser utilizado na funcao de dfs, criado com tamanho n e setado todos os elementos como falso
    vector<bool> visited(n, false);
    // grafo conectado com a matriz de adjacencia criada
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(1, 4);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 5);
    g.adicionarAresta(5, 6);
    g.adicionarAresta(5, 7);
    g.adicionarAresta(5, 8);
    g.adicionarAresta(7, 8);
    g.adicionarAresta(8, 9);
    //imprimindo a matriz
    cout << "Matriz original:\n";
    g.imprime_matriz();
    cout << endl
         << endl;
    //fazendo a busca em profundidade de todos os elementos do grafo
    cout << "Ordem da busca em profundidade(DFS)\n";
    g.dfs(0, visited);

    cout << endl;

    //fazendo a busca em largura dos elementos, iniciando no vertice 0
    cout << "Ordem da busca em largura (BFS)\n";
    g.bfs(0);
    cout << endl
         << endl;

    // adicionando um novo vertice no grafo
    g.adicionarVertice();

    //conectando o novo vertice a outros, fazendo com que ele se torne um vertice conexo
    g.adicionarAresta(10, 4);
    g.adicionarAresta(10, 5);

    // a matriz, após esse novo vértice
    cout << "Matriz com novo vertice:\n";
    g.imprime_matriz();
    cout << endl
         << endl;

    // removendo o vertice 1 da matriz
    cout << "Matriz com o vertice removido:\n";
    g.removerVertice(1);
    // a matriz de adjacencia apos a remocao
    g.imprime_matriz();
    cout << endl
         << endl;

    return 0;
}
