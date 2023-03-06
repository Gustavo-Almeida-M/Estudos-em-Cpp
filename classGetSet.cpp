#include <iostream>

using namespace std;

class Person
{
    private:
    string name;
    public:
    int age;

    Person(string cName, int cAge)
    {
        age = cAge;
    }
    void setName(string sName)
    {
        name = sName;
    }
    void getName()
    {
        cout << name;
    }
};

int main()
{
    Person person1("", 18);
    person1.setName("Gustavo");
    person1.getName();
}