#include <iostream>

int fibo(int qtd)
{
    int valor1 = 0, valor2 = 1, aux = 0;
    if(qtd <= 1)
    {
        return valor1;
    }
    else if(qtd == 2)
    {
        return valor2;
    }
    else
    {
        for(int i = 2; i < qtd; i++)
        {
            aux = valor1 + valor2;
            valor1 = valor2;
            valor2 = aux;
        } 
    }
    return valor2;
}

int main()
{
    int qtd = 0;
    std::cout << "Digite qual a posição do numero da sequencia de fibonacci voce deseja: ";
    std::cin >> qtd;
    std::cout << "F(" << qtd << ") = " << fibo(qtd) << std::endl;
    return 0;

    
}