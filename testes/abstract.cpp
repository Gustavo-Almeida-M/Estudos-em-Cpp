#include <iostream>

using namespace std;

class AbstratctTeste
{
    virtual void AskForPrototype()=0;
};

class Teste1
{
    public:
    string name;
    int age;
    Teste1(string cName, int cAge)
    {
        name = cName;
        age = cAge;
    }
    void AskForPrototype()
    {
        if(age > 25)
        {
            cout << name << " você ganhou uma promoção no seguro!";
        }
    }
};

int main()
{
    Teste1 teste0("Gustavo", 65);
    teste0.AskForPrototype();
}