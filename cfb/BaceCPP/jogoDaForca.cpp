#include <iostream>
using namespace std;

int main()
{
    cout << "Termo, digite uma palavra\n";

    char palavra[30], letra, secreta[30];
    int tamanho = 0, chances = 6, acertos = 0;
    bool acerto = false;

    cout << "Digite a palavara secreta: ";
    cin >> palavra;

    int i = 0;

    while(palavra[i] != '\0')
    {
        i++;
        tamanho++;
    }

    for(i = 0; i < tamanho; i++)
    {
        secreta[i] = '-';
    }
    while(chances > 0 && acertos < tamanho)
    {
        cout << "Chances restantes: " << chances << "\n";
        cout << "Digite uma letra para chutar:";
        cin >> letra;
        for(i = 0; i < tamanho; i++)
        {
            if(palavra[i] == letra)
            {
                acertos++;
                acerto = true;
                secreta[i] = palavra[i];
                cout << secreta << "\n";
            }
        }
        if(!acerto)
        {
            chances--;
        }
        acerto = false; 
    } 
    if(acertos == tamanho)
    {
        cout << "Ganhou!!";
    }
}