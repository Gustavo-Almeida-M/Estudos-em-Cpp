#include <iostream>
#include "pilha.h"

    pilha::pilha()
    {
        tamanho = 0;
        estrutura = new TipoItem[max_itens];
    }

    pilha::~pilha()
    {
        delete [] estrutura;
    }

    bool  pilha::estaCheia()
    {
        return (tamanho == max_itens);
    }

    bool  pilha::estaVazia()
    {
        return (tamanho == 0);
    }

    void  pilha::inserir(TipoItem item)
    {
        if(estaCheia)
        {
            std::cout << "A pilha está cheia\n";
            std::cout << "Não é possivel adicionar mais itens\n";
        }
        else
        {
            estrutura[tamanho] == item;
            tamanho++;
        }
    }

    TipoItem  pilha::remover()
    {
        if(estaVazia())
        {
            std::cout << "A pilha está vazia\n";
            std::cout << "Não tem itens para serem removidos\n";
            return 0;
        }
        else
        {
            tamanho--;
            return estrutura[tamanho];
        }
    }

    void  pilha::imprimir()
    {
        std::cout << "Pilha [";
        for(int i = 0; i < tamanho; i++)
        {
            std::cout << estrutura[i] << " ";
        }
        std::cout << "]\n";
    }

    int  pilha::qualTamanho()
    {
        return tamanho;
    }