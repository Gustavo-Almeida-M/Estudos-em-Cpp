/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/
#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>
#include <sstream>


//o código dessas funções se encontra mais abaixo
SparseMatrix* readSparseMatrix(const std::string&);


SparseMatrix* sum(SparseMatrix*, SparseMatrix*);

SparseMatrix* multiply(SparseMatrix*, SparseMatrix*);



int main()
{
    std::vector<SparseMatrix *> matrix;
    std::cout << "\033[1m" << std::endl;
    std::cout << "--------------------------------------------------------\n";
    std::cout << "ED - Matriz Esparsa - Elysson Alves & Gustavo Almeida \n";
    std::cout << "---------------------------------------------------------\n";
    std::cout << "\033[0m" << std::endl;
    // Lista de comando do usuario
    std::cout << "Lista de comandos: \n criar -> para criar uma nova matriz \n copiar -> para copiar uma matriz para outra \n inserir -> para adicionar um valor na posicao selecionada \n remover-> para remover um valor na posicao selecionada \n";
    std::cout << " somar -> para imprimir a soma de duas matrizes \n multiplicar -> para imprimir a multiplicacao de duas matrizes \n get -> para imprimir o valor de uma posicao especifica \n show -> para imprimir as matrizes \n load -> para carregar um arquivo com testes\n sair -> para terminar as operacoes\n";
    std::cout << "----------------------------------------------------------\n";

    while(true)
    {

        std::string comando, token;
        std::getline(std::cin, comando);
        std::stringstream ss(comando);
        ss >> token;

        std::cout << "$" << ss.str() << std::endl;

        if (token == "sair")
        {
            for (unsigned i = 0; i < matrix.size(); i++)
            {
                delete matrix[i];
            }
            matrix.clear();
            break;
        }
        else if (token == "criar")
        {
            char linhas, colunas;
            std::cout << "Digite o numero de linhas e colunas: ";
            std::cin >> linhas >> colunas;
            int cLinhas = static_cast<int>(linhas);
            int cColunas =  static_cast<int>(colunas);
            std::cin.ignore();
            SparseMatrix* lst = new SparseMatrix(cLinhas, cColunas);
            matrix.push_back(lst);

            std::cout << "Matriz criada com sucesso \n";
        }
        else if(token == "copiar")
        {
            int nMatriz;
            std::cout << "Digite o numero da matriz para ser copiada\n";
            std::cin >> nMatriz;
            SparseMatrix* lst = new SparseMatrix(matrix[nMatriz]->getLinhas(), matrix[nMatriz]->getColunas());
            SparseMatrix* aux = new SparseMatrix(matrix[nMatriz]->getLinhas(), matrix[nMatriz]->getColunas());
            lst->copiar(aux);
            matrix.push_back(lst);
            std::cout << "Copiado com sucesso\n";
            std::cin.ignore();
        }
        else if (token == "inserir")
        {
            int nMatriz, linha, coluna;
            double valor;
            
            std::cout << "Digite: numero da matriz, linha, coluna e o valor para ser adicionado\n";
            std::cin >> nMatriz >> linha >> coluna >> valor;
            if(nMatriz < matrix.size() && nMatriz >= 0)
            {
                (matrix[nMatriz]->insert(linha, coluna, valor))? std::cout << "Valor inserido com sucesso\n" : std::cout << "Erro ao inserir, confira os dados de entrada";
                std::cin.ignore();
            }
            else
            {
                std::cout << "Erro ao INSERIR, confira os dados de entrada\n";
            }
        }
        else if (token == "remover")
        {
            int nMatriz, linha, coluna;

            std::cout << "Digite: numero da matriz, linha e coluna para que o valor seja removido\n";
            std::cin >> nMatriz >> linha >> coluna;
            if(nMatriz < matrix.size() && nMatriz >= 0)
            {
                (matrix[nMatriz]->remove(linha, coluna))?std::cout << "Removido com sucesso\n":
                std::cout << "Erro ao REMOVER, confira os dados de entrada\n";
            }
            
            std::cin.ignore();
        }
        else if (token == "somar")
        {
            int matriz1, matriz2;
            std::cout << "Digite quais matrizes quer somar: \n";
            std::cin >> matriz1 >> matriz2;
            if((matriz1 < matrix.size() && matriz2 < matrix.size())&& (matriz1 >= 0 && matriz2 >= 0))
            {
                SparseMatrix* resultado = sum(matrix[matriz1], matrix[matriz2]);

                resultado->print();

                delete resultado;

                std::cin.ignore();
            }
            else
            {
                std::cout << "Erro ao SOMAR, confira os dados de entrada\n";
                std::cin.ignore();
            }
        }
        else if (token == "multiplicar")
        {
            int matriz1, matriz2;
            std::cout << "Digite quais matrizes quer multiplicar: \n";
            std::cin >> matriz1 >> matriz2;

            if((matriz1 < matrix.size() && matriz2 < matrix.size())&& (matriz1 >= 0 && matriz2 >= 0))
            {
                SparseMatrix* resultado = multiply(matrix[matriz1], matrix[matriz2]);

                resultado->print();

                delete resultado;

                std::cin.ignore();
            }
            else
            {
                std::cout << "Erro ao MULTIPLICAR, confira os dados de entrada\n";
                std::cin.ignore();

            }
        }
        else if (token == "get")
        {
            int nMatriz, linha, coluna;

            std::cout << "Digite: numero da matriz, linha e coluna: \n";
            std::cin >> nMatriz >> linha >> coluna;
            double valor = matrix[nMatriz]->get(linha, coluna);
            std::cout << "Valor: " << valor << std::endl;
            std::cin.ignore();
        }
        else if (token == "show")
        {
            for (unsigned i = 0; i < matrix.size(); i++)
            {
                std::cout << "Matriz: " << i << '\n';
                matrix[i]->print();
                std::cout << '\n';
            }
        }
        else if (token == "load")
        {
            std::string filename;
            std::cout << "Digite o nome do arquivo: \n";
            ss >> filename;
            SparseMatrix* matriz = readSparseMatrix(filename);
            matrix.push_back(matriz);
        }
        else
        {
            std::cout << "Comando inexistente" << std::endl;
        }
    }

    return 0;
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B) {
    SparseMatrix* aux = new SparseMatrix(B->getColunas(), A->getLinhas());
    if (A->getColunas() == B->getLinhas()) {
        for (int i = 0; i < A->getLinhas(); i++) { 
            for (int j = 0; j < B->getColunas(); j++) {
                double temp = 0;
                for (int k = 0; k < A->getColunas(); k++) {
                    temp += A->get(i, k) * B->get(k, j);
                }
                aux->insert(i, j, temp);
            }
        }
        return aux;
    } else {
        std::cout << "Nao e possivel multiplicar as matrizes\n";
        return aux;
    }
}
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B) {
    int linhas = A->getLinhas();
    int colunas = A->getColunas();

    SparseMatrix* aux = new SparseMatrix(linhas, colunas);


    if (A->getLinhas() == B->getLinhas() && A->getColunas() == B->getColunas()) {
        for(int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                double valueA = A->get(i, j);
                double valueB = B->get(i, j);
                double value = valueA + valueB;
                
                if (value != 0.0) {
                    aux->insert(i, j, value);
                }
            }
        }

        return aux;
    } else {
        std::cout << "Não é possível somar as matrizes\n";
        return aux;
    }
}


SparseMatrix* readSparseMatrix(const std::string& filename)
{
    std::ifstream file(filename);
    int linhas, colunas, linha, coluna;
    double valor;

    file >> linhas >> colunas;
    SparseMatrix* matrix = new SparseMatrix(colunas, linhas);
    while (file >> linha >> coluna >> valor) {
        matrix->insert(linha, coluna, valor);
    }

    return matrix;
}
