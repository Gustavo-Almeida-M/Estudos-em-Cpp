
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    char teste = ' ';
    getline(cin, s1);
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == teste && s1[i - 1] == s1[i + 1])
        {
            i++;
        }
        else
        {
            cout<< s1[i];
        }
    }
}