#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c, int vezes)
{
    if(n == 0)
    {
        if(str[n] == c)
        {
            vezes++;
        }
        return vezes;
    }
    else if(str[n] == c)
    {
        vezes++;
    }
    return contaCaracteres(str, n - 1, c, vezes);
}

int main() 
{
    string frase;
    getline(cin, frase);
    
    char caractere;
    cin >> caractere;
    
    int tamanho = frase.length();
    
    cout << contaCaracteres(frase, tamanho, caractere, 0);
}