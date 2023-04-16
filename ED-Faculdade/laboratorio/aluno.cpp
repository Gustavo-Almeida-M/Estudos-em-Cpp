#include <iostream>

using namespace std;

struct aluno
{
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
};

bool passou(double valor)
{
    if(valor >= 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    aluno aluno1;
    cin >> aluno1.nome >> aluno1.matricula >> aluno1.disciplina >> aluno1.nota;
    if(passou(aluno1.nota))
    {
        cout << aluno1.nome << " aprovado(a) em " << aluno1.disciplina;
    }
    else
    {
        cout << aluno1.nome << " reprovado(a) em " << aluno1.disciplina;
    }
}