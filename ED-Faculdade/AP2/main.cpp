/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/
#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>

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


SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B) {
    if (A->getLinhas() == B->getLinhas() && A->getColunas() == B->getColunas())
    {
        SparseMatrix* aux = new SparseMatrix(A->getLinhas(), A->getColunas());

        for(int i = 0; i < A->getLinhas(); i++) {
            for (int j = 0; j < A->getColunas(); j++) {
                double valueA = A->get(i, j);
                double valueB = B->get(i, j);
                double value = valueA + valueB;
                
                if (value != 0.0) {
                    aux->insert(i, j, value);
                }
            }
        }

        return aux;
    } else
    {
        std::cout << "Nao e possivel somar as matrizes\n";
        return 0;
    }
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B) {
    if (A->getColunas() == B->getLinhas()) {
        SparseMatrix* aux = new SparseMatrix(B->getColunas(), A->getLinhas());
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
        throw std::runtime_error("As matrizes nao podem ser multiplicadas");
    }
}




int main()
{
    std::vector<SparseMatrix*> matrix;

    while(true)
    {
        std::string comando, token;
        std::getline(std::cin, comando);
        std::stringstream ss(comando);
        ss >> token;

        std::cout << "$" << ss.str() << std::endl;

        if (token == "exit")
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
            int linhas, colunas;
            std::cout << "Digite o numero de linhas e colunas: ";
            std::cin >> linhas >> colunas;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            SparseMatrix* lst = new SparseMatrix(colunas, linhas);
            matrix.push_back(lst);
        }
        else if(token == "copiar")
        {
            int nMatriz;
            ss >> nMatriz;
            SparseMatrix* lst = new SparseMatrix(*matrix[nMatriz]);
            matrix.push_back(lst);
        }
        else if (token == "inserir")
        {
            int nMatriz, linha, coluna;
            double valor;
            std::cin >> nMatriz >> linha >> coluna >> valor;
            matrix[nMatriz]->insert(linha, coluna, valor);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (token == "remover")
        {
            int nMatriz, linha, coluna;
            std::cin >> nMatriz >> linha >> coluna;
            matrix[nMatriz]->remove(linha, coluna);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (token == "soma")
        {
            int matriz1, matriz2;
            std::cout << "Digite quais matrizes quer somar: \n";
            std::cin >> matriz1 >> matriz2;

            SparseMatrix* resultado = sum(matrix[matriz1], matrix[matriz2]);

            // Faça algo com a matriz resultado, como imprimir seus valores
            resultado->print();

            // Lembre-se de liberar a memória alocada para a matriz resultado
            delete resultado;

            std::cin.ignore();
        }
        else if (token == "multiplicar")
        {
            int matriz1, matriz2;
            std::cout << "Digite quais matrizes quer multiplicar: \n";
            std::cin >> matriz1 >> matriz2;

            SparseMatrix* resultado = multiply(matrix[matriz1], matrix[matriz2]);

            // Faça algo com a matriz resultado, como imprimir seus valores
            resultado->print();

            // Lembre-se de liberar a memória alocada para a matriz resultado
            delete resultado;

            std::cin.ignore();
        }
        else if (token == "get")
        {
            int nMatriz, linha, coluna;
            std::cin >> nMatriz >> linha >> coluna;
            double valor = matrix[nMatriz]->get(linha, coluna);
            std::cout << "Valor: " << valor << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (token == "show")
        {
            for (unsigned i = 0; i < matrix.size(); i++)
            {
                matrix[i]->print();
            }
        }
        else if (token == "load")
        {
            std::string filename;
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

