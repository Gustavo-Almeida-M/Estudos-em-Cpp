#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

SparseMatrix* readSparseMatrix(std::string);

SparseMatrix* sum(SparseMatrix*, SparseMatrix*);

SparseMatrix* multiply(SparseMatrix*, SparseMatrix*);


int main()
{
	vector<SparseMatrix*> matrix;
	
	while(true) {
		string comando, token;
		getline(cin, comando);
		stringstream ss{ comando };
        ss >> token;

        cout << "$" << ss.str() << endl;

		// exit
		if(token == "exit") {
			for(unsigned i = 0; i < matrix.size(); i++)
				delete matrix[i];
			matrix.clear();
			break;
		}
		// create
		// create
        else if (token == "create")
        {
        cout << "Digite o numero de linhas e colunas\n";
        int linhas, colunas;
        cin >> linhas >> colunas;
        cin.ignore();
        SparseMatrix *lst = new SparseMatrix(linhas, colunas);
        matrix.push_back(lst);
        cin.ignore();
        }  

		// createWith l
		else if(token == "copia") 
        {
			int nMatriz;
            ss >> nMatriz;
			SparseMatrix lst =  matrix[nMatriz]->copia();
		}
        // removeAll x l
		else if(token == "remove") {
			int nMatriz, linha, coluna;
            
            cin >> nMatriz >> linha >> coluna;

			matrix[nMatriz]->remove(linha, coluna);
		}
        // equals l1 l2 
		// get i l
		else if(token == "get") 
        {
			int nMatrix, linha, coluna;
			cin >> nMatrix >> linha >> coluna;
			cout << matrix[nMatrix]->get(linha, coluna);
		}
        // show 
		else if(token == "show") 
        {
            for(unsigned i = 0; i < matrix.size(); i++) 
            {
                (*matrix[i]).print();
            }	
		}
		else 
        {
			cout << "comando inexistente" << endl;
		}
	}

}
SparseMatrix* readSparseMatrix(std::string filename)
{  // Complexidade : O(n)
    std::ifstream file(filename);
    int linhas, colunas, linha, coluna;
    double valor;

    file >> linhas >> colunas;
    SparseMatrix* matrix = new SparseMatrix(linhas, colunas);
    while(file >> linha >> coluna >> valor)
    {
            matrix->insert(linha, coluna, valor);
    }

    return matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B)
{ //O(n²)
        if(A->getLinhas() == B->getLinhas() && A->getColunas() == B->getColunas())
        {
            SparseMatrix* aux = new SparseMatrix(A->getLinhas(), A->getColunas()); // Cria uma matriz auxiliar
            for(int i =1; i <= A->getLinhas(); i++)
            { // Percorre as linhas
                for(int j = 1; j <= A->getColunas(); j++)
                {  // Percorre as colunas
                    aux->insert(i, j, A->get(i, j) + B->get(i, j));  // Insere o valor da soma na matriz auxiliar
                }
            }
            return aux; // Retorna a matriz auxiliar
        }
        else{
            throw std::runtime_error("As matrizes nao podem ser somadas");
        }
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B)
{ //O(n³)
    if(A->getColunas() == B->getLinhas())
    {
        SparseMatrix* aux = new SparseMatrix(A->getLinhas(), B->getColunas());

        for (int i = 1; i <= aux->getLinhas(); i++)
        { // Percorrer as linhas
            for (int j = 1; j <= aux->getColunas(); j++)
            { // Percorrer as colunas
                double temp = 0;
                for (int k = 1; k <= A->getColunas(); k++)
                { // Realizar a multiplicação
                    temp += A->get(i, k) * B->get(k, j);
                }       
                aux->insert(i, j, temp);
            }
        }
        return aux;
    }
    else
    {
        throw std::runtime_error("As matrizes nao podem ser multiplicadas");
    }
}
