/**
 * @file main.cpp
 * @author Elysson & Gustavo
 * @brief 
 * @version 0.1
 * @date 2023-07-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "List.h"

using namespace std;

void gera_dados(const int vetor_tam[]);

void ler_dados(int n, int A[], const char* nomeArquivo);

long double calcular_tempo_medio(List& lst, int tamanho_vetor, const string& nome_arquivo, const string& algoritmo);

void gravar_resultado(const string& nome_arquivo, int tamanho_vetor, long double duracao_media);


int main()
{
    const int tam[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,
                        11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000,
                        20000,21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000,
                        29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000,
                        38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000,
                        47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000,
                        56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000,
                        65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000,
                        74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000,
                        83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000,
                        92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000};
    const int TOTAL_N = sizeof(tam) / sizeof(tam[0]);

    gera_dados(tam);

    for (int iteracao = 0; iteracao < TOTAL_N; iteracao++)
	{
        List lst;
        const int tamanho_vetor = tam[iteracao];

        long double duracao_media_quick = 0.0;
        long double duracao_media_merge = 0.0;
        long double duracao_media_insertion = 0.0;
        long double duracao_media_selection = 0.0;
        long double duracao_media_sharke = 0.0;
        long double duracao_media_bubble = 0.0;

        for (int semente = 0; semente < 5; semente++) {
            string nome_arquivo = "dados/random" + to_string(iteracao) + "_" + to_string(semente) + ".dat";

            duracao_media_quick += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "quick");
            duracao_media_merge += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "merge");
            duracao_media_insertion += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "insertion");
            duracao_media_selection += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "selection");
            duracao_media_sharke += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "sharke");
            duracao_media_bubble += calcular_tempo_medio(lst, tamanho_vetor, nome_arquivo, "bubble");
        }

        duracao_media_quick /= 5.0;
        duracao_media_merge /= 5.0;
        duracao_media_insertion /= 5.0;
        duracao_media_selection /= 5.0;
        duracao_media_sharke /= 5.0;
        duracao_media_bubble /= 5.0;

        gravar_resultado("resultados/resultadoQuick.txt", tamanho_vetor, duracao_media_quick);
        gravar_resultado("resultados/resultadoMerge.txt", tamanho_vetor, duracao_media_merge);
        gravar_resultado("resultados/resultadoInsertion.txt", tamanho_vetor, duracao_media_insertion);
        gravar_resultado("resultados/resultadoSelection.txt", tamanho_vetor, duracao_media_selection);
        gravar_resultado("resultados/resultadoSharke.txt", tamanho_vetor, duracao_media_sharke);
        gravar_resultado("resultados/resultadoBubble.txt", tamanho_vetor, duracao_media_bubble);
    }

	cout << "Terminou \n";
    int valor;
    cin >> valor;

    return 0;
}
// Fim da Main ----------------------------------------------------------------------------------------------------------------------

//Função para gerar os dados de entrada
void gera_dados(const int vetor_tam[])
{
    for (int n = 0; n < 5; ++n)
	{
        for (int semente = 0; semente < 5; semente++)
		{
            string nome_arquivo = "dados/random" + to_string(n) + "_" + to_string(semente) + ".dat";
            ofstream fout(nome_arquivo.c_str(), ios::binary);
            random_device rd;
            mt19937 mt(rd());
            uniform_int_distribution<int> dist(0, 1000);
            int tamanho_vetor = vetor_tam[n];
            for (int i = 0; i < tamanho_vetor; i++)
			{
                int r = dist(mt);
                fout.write((char*)&r, sizeof(r));
            }
            fout.close();
        }
    }
}

//Função para ler os dados dos arquivos
void ler_dados(int n, int A[], const char* nomeArquivo)
{
    ifstream input_file(nomeArquivo, ios::binary);
    for (int i = 0; i < n; i++) {
        input_file.read((char*)&A[i], sizeof(int));
    }
    input_file.close();
}

//Função para calcular o tempo de execução 
long double calcular_tempo_medio(List& lst, int tamanho_vetor, const string& nome_arquivo, const string& algoritmo)
{
    int vetor[tamanho_vetor];
    ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());

    for (int i = 0; i < tamanho_vetor; i++)
	{
        lst.push_back(vetor[i]);
    }

    auto ini = chrono::high_resolution_clock::now();

    if (algoritmo == "quick")
	{
        lst.quick_sort();
		//cout << "Quick\n";
		//lst.print();
    } else if (algoritmo == "merge")
	{
        lst.merge_sort();
		//cout << "merge\n";
		//lst.print();
    } else if (algoritmo == "insertion")
	{
        lst.insertion_sort();
		//cout << "insertion\n";
		//lst.print();
    } else if (algoritmo == "selection")
	{
        lst.selection_sort();
		//cout << "selection\n";
		//lst.print();
    } else if (algoritmo == "sharke")
	{
        lst.shaker_sort();
		//cout << "Sharke\n";
		// lst.print();
    } else if (algoritmo == "bubble")
	{
        lst.bubble_sort();
		//cout << "Bubble\n";
		// lst.print();
    }

    auto fim = chrono::high_resolution_clock::now();

    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
    lst.clear();

    return duracao;
}

void gravar_resultado(const string& nome_arquivo, int tamanho_vetor, long double duracao_media)
{
    ofstream ofs(nome_arquivo, ofstream::out | ofstream::app);
    ofs << tamanho_vetor << " " << duracao_media << "\n";
    ofs.close();
}
