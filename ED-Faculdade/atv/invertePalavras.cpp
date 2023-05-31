#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void inverte_palavra(string& sentenca)
{
    stringstream ss{sentenca};
    string palavra;
    while(ss >> palavra)
    {
        stack<char> pilha;
        for(int i : palavra)
        {
            pilha.push(i);
        }
        while (!pilha.empty())
        {
            cout << pilha.top();
            pilha.pop();
        }
        cout << endl;
    }
}

int main()
{
    string nome{"oiac oana ordep"};
    inverte_palavra(nome);

}