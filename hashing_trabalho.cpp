// EM DUPLAS] Implemente uma Tabela Hash com endereçamento aberto usando sondagem quadrática para armazenar os nomes das cidades de Minas Gerais em um array e
//  imprima estatísticas do número de colisões para os seguintes cenários (teste com 5 tamanhos diferentes da tabela):
// a. Método da divisão ok
// b. Método da multiplicação (com constante) ok
// c. Método da multiplicação (meio do quadrado)
// d. Método da dobra
#include <iostream>
#include <string.h>
#include <tgmath.h>
using namespace std;
#define MAX 10000
#define PRIME 7

string cidades_div[1000];
string cidades_multC[850000];
string cidades_multQ[950000];
string cidades_dobra[10000];

int contdiv = 0, contmultC = 0, contmultQ = 0, contdobra = 0;

int hash_metodo_divisao(string cidade, int x)
{
    bool avai = false;
    // int x = 0;
    // for (int i = 0; i <= cidade.length(); i++)
    // {
    //     x += cidade[i];
    // }
    int pos = x % 85000;
    while (!avai)
    {
        if (cidades_div[pos].empty())
        {
            cidades_div[pos] = cidade;
            avai = true;
            return pos;
        }
        else
        {
            pos = (pos * pos) % 85000;
            contdiv++;
        }
    }

    return pos;
}

int hash_metodo_multiplicacao_constante(string cidade, int x)
{
    x = double(x);
    bool avai = false;
    x = x * 0.618339887;
    x = x - ((int)x);
    double aux = x * 850000;
    unsigned long long int chave = aux;
    unsigned long long int pos = chave;
    float i = 1;
    while (!avai)
    {
        if (cidades_multC[pos].empty())
        {
            cidades_multC[pos] = cidade;
            avai = true;
            return pos;
        }
        else
        {
            pos = (int)(chave * 0.618339887) + pow(i, 2);
            contmultC++;
            i++;
        }
    }
    return (int)aux;
}

int countDigit(unsigned long long n)
{
    double count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int hash_metodo_multiplicacao_quadrado(string cidade, int x)
{
    unsigned long long aux = 0;
    bool avai = false;
    double div = 0, numdig = 0;
    // for (unsigned long long i = 0; i <= cidade.length(); i++)
    // {
    //     x += cidade[i];
    // }
    aux = x * x;

    numdig = countDigit(aux);
    div = numdig / 2;
    div = ceil(div);
    int div2 = (int)div;

    int arr[(int)numdig];
    for (int i = (int)numdig; i >= 0; i--)
    {
        arr[i] = aux % 10;
        aux /= 10;
    }
    //o tamanho desse array varia de acordo com o tamanho da tabela. Aqui consideramos = 1000.
    //  Por esse motivo, não utilizei uma forma mais sofisticada de extrai o meio do inteiro a fim de facilitar o entendimento do codigo
    unsigned long long arr2[3];
    arr2[0] = arr[(unsigned long long)div - 1];
    arr2[1] = arr[(unsigned long long)div];
    arr2[2] = arr[(unsigned long long)div + 1];

    unsigned long long pos = 0;
    for (unsigned long long i = 0; i < 3; i++)
    {
        pos *= 10;
        pos += arr2[i];
    }
    unsigned long long chave = pos;
    float i = 1;
    while (!avai)
    {
        if (cidades_multQ[pos].empty())
        {
            cidades_multQ[pos] = cidade;
            avai = true;
            return pos;
        }
        else
        {
            pos = (chave * chave) + pow(i, 2);
            i++;
            contmultQ++;
        }
    }
    return pos;
}

//devido aos inuméros erros obtidos e por conta do fator tempo também. Tive de quebrar o "padrao" do codigo e ao inves de utilizar uma função aqui, utilizei uma classe, sendo mais fácil instanciar um objeto, e trabalhar nas operacoes.
class DobraHash
{
    // pointer
    int *hashTable;
    int tamanho_atual;

public:
    // calculate first hash
    int hash1(int key)
    {
        return (key % 10000);
    }

    // calculate second hash
    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }

    DobraHash()
    {
        hashTable = new int[10000];
        tamanho_atual = 0;
        for (int i = 0; i < 10000; i++)
            hashTable[i] = -1;
    }

    // function to insert key into hash table
    void insere(int key)
    {

        int pos = hash1(key);

        // se houver colisoes
        if (hashTable[pos] != -1)
        {
            int pos2 = hash2(key);
            int i = 1;
            while (1)
            {
                // nova posicao
                int newPos = (pos + i * pos2) % 10000;

                // if no collision occurs, store
                // the key
                if (hashTable[newPos] == -1)
                {
                    hashTable[newPos] = key;
                    break;
                }
                i++;
                contdobra++;
            }
        }
        else
            hashTable[pos] = key;
        tamanho_atual++;
    }
};

int main()
{
    string cidade;
    int arrsize = 0;
    DobraHash h;

    while (getline(cin, cidade))
    {
        // caso ambas as tabelas estejam full lotadas
        if (contmultC >= 9 || contmultQ >= 9)
        {
            break;
        }

        int x = 0;
        for (int i = 0; i < cidade.length(); i++)
        {
            x += cidade[i];
        }
        hash_metodo_divisao(cidade, x);
        hash_metodo_multiplicacao_constante(cidade, x);
        hash_metodo_multiplicacao_quadrado(cidade, x);
        h.insere(x);
    }
    cout << "Quantidade de vezes que tivemos colisoes no metodo da divisao: " << contdiv << endl;
    cout << "Quantidade de vezes que tivemos colisoes no metodo da multiplicacao com constante: " << contmultC << endl;
    cout << "Quantidade de vezes que tivemos colisoes no metodo da multiplicacao quadratica: " << contmultQ << endl;
    cout << "Quantidade de vezes que tivemos colisoes no metodo da dobra: " << contdobra << endl;

    return 0;
}