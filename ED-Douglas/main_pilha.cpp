#include <iostream>
#include "pilha.h"

int main()
{
    pilha pilha1;
    TipoItem item;
    int opcao = 0;
    std::cout << "Programa gerador de pilha" << std::endl;    

    do
    {
        std::cout << "Digite 0 para parar o programa!\n";
        std::cout << "Digite 1 para inserir um elemento\n";
        std::cout << "Digite 2 para remover um elemento\n";
        std::cout << "Digite 3 para imprimir a pilha um elemento\n";
        std::cout << "Digite 4 para imprimir o tamanho da pilha elemento\n";
        std::cin >> opcao;
        if(opcao == 1){
            std::cout << "Digite um valor: \n";

            std::cin >> item;
            pilha1.inserir(item);
        }
        else if(opcao == 2)
        {
            item = pilha1.remover();
        }
        else if(opcao == 3)
        {
            pilha1.imprimir();
        }
        else if(opcao == 4)
        {
            std::cout << pilha1.qualTamanho() << " \n";
        }             
    } while (opcao !=0);

}