#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> pilha;

    string input, palavra;
    cout << "Digite uma lista de nomes: ";
    getline(cin, input);
    
    stringstream ss{input};
    while(ss >> palavra)
    {
        pilha.push(palavra);
    }

    while(!pilha.empty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
    cout << "Size da pilha: " << pilha.size();
}