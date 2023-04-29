//Programa usando alocação dinamica de memoria
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *nome;
    nome= static_cast<char *> (malloc(sizeof(char) + 1));

    gets(nome);
    std::cout << nome;
}