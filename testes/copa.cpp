#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> times {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    vector<char> vencedores;
    vector<int> gols;
    
    for(int i = 0, j = 0; i < 8; i++, j + 2)
    {
        int gols1, gols2;
        cin >> gols1 >> gols2;
        
        (gols1 > gols2)? vencedores.push_back(times[j]) : vencedores.push_back(times[j + 1]);
    }
    for(int i = 0, j = 0; i < 4; i++, j+= 2)
    {
        int gols1, gols2;
        cin >> gols1 >> gols2;
        
        (gols1 > gols2)? vencedores.push_back(vencedores[j]) : vencedores.push_back(vencedores[j + 1]);
    }
    for(int i = 0, j = 7; i < 2; i++, j+= 2)
    {
        int gols1, gols2;
        cin >> gols1 >> gols2;
        
        (gols1 > gols2)? vencedores.push_back(vencedores[j]) : vencedores.push_back(vencedores[j + 1]);
    }
    int j = 9;
    int gols1, gols2;
    cin >> gols1 >> gols2;
    (gols1 > gols2)? vencedores.push_back(vencedores[j]) : vencedores.push_back(vencedores[j + 1]);

    auto vencedor = vencedores.back();

    cout << vencedor;
}