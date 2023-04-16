//Busca de alunos atraves da matricula
#include <iostream>
#include <iomanip>

using namespace std;

struct aluno
{
    int matricula;
    char nomeCompleto[100];
    float media;
};
int main()
{
    int qtdAlunos;
    cin >> qtdAlunos;
    aluno alunos[qtdAlunos];
    for(int i = 0; i < qtdAlunos;i++)
    {
        char aux[100];
        cin >> alunos[i].matricula;
        cin.ignore();
        cin.get(alunos[i].nomeCompleto, 100);
        cin >> alunos[i].media;
    }
    int procuraMatricula;
    cin >> procuraMatricula;
    for(int i = 0; i < qtdAlunos;i++)
    {
        cout << fixed << setprecision(1);
        if(procuraMatricula == alunos[i].matricula)
        {
            cout << alunos[i].nomeCompleto << "\n" << alunos[i].media;
            return 1;
        }
    }
    cout << "NAO ENCONTRADA";
}