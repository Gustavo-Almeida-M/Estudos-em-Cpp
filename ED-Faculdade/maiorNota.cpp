#include <iostream>
#include <iomanip>

using namespace std;

void maiorNota(char nome1[], char nome2[], float nota1, float nota2)
{
    cout << fixed << setprecision(1);
    if(nota1 == nota2)
    {
        cout << nome1 << " e " << nome2 << " , " << nota1;
    }
    else if(nota1 > nota2)
    {
        cout << nome1 << " , " << nota1;
    }
    else
    {
        cout << nome2 << " , " << nota2;
    }
}

struct aluno
{
    char nome[30];
    int matricula;
    char materia[30];
    float nota;
};

int main()
{
    aluno aluno1, aluno2;
    cin >> aluno1.nome >> aluno1.matricula >> aluno1.materia >> aluno1.nota;
    cin >> aluno2.nome >> aluno2.matricula >> aluno2.materia >> aluno2.nota;
    maiorNota(aluno1.nome, aluno2.nome, aluno1.nota, aluno2.nota);
}