#include <iostream>
#include <vector>


int main()
{
    std::vector<int> contasUsuario{12345, 11111, 33333, 44444};

    std::cout << "Welcome\n" << "Digite o numero da sua conta\n";

    bool naoAprovado = true;

    while(naoAprovado)
    {
        int numeroContaAcesso;
        std::cin >> numeroContaAcesso;

        for(int i = 0; i < contasUsuario.size(); i++)
        {
            if(numeroContaAcesso == contasUsuario[i])
            {
                std::cout << "Conta aprovada\n";
                naoAprovado = false;
                break;
            }
            if(i == contasUsuario.size() - 1)
            {
                std::cout << "Conta nao aprovada\n";
                std::cout << "digite novamente sua conta:\n";
            }
        }
        
    }
}