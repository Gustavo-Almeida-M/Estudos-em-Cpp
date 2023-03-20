#include <iostream>
#include "pilha.h"

int main()
{
    pilha pilha1;
    TipoItem item;
    int opcao;
    std::cout << "Programa gerador de pilha" << std::endl;    

    do
    {
        std::cout << "Digite 0 para parar o programa!\n";
        std::cout << "Digite 1 para inserir um elemento\n";
        std::cout << "Digite 2 para remover um elemento\n";
        std::cout << "Digite 1 para imprimir a pilha um elemento\n";
        std::cout << "Digite 1 para imprimir o tamanho da pilha elemento\n";
    } while (opcao !=0);
    
}