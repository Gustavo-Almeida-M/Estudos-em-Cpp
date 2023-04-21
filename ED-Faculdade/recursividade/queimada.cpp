#include <iostream>
#include <string>
using namespace std;


void show(string *mat, int nl) 
{
    for(int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(int nl, int nc, string* mat, int l, int c)
{
mat[l][c] = 'o';
bool queimada = true;

    while(queimada)
    {
        queimada = false;
        
        for(int i = 0; i < nl; i++)
        {
            // cout << mat[0][i + 1] << " <-- valor\n";
            for(int j = 0; j < nc; j++)
            {
                if(mat[i][j] == '#')
                {
                    if((i > 0 && mat[i-1][j] == 'o')//Em baixo
                    ||(i < nl-1 && mat[i+1][j] == 'o')//Em cima
                    ||(j > 0 && mat[i][j-1] == 'o')//Lateral direita
                    ||(j < nc-1 && mat[i][j+1] == 'o'))//Lateral esquerda
                    {
                        mat[i][j] = 'o';
                        queimada = true;
                    }
                }  
            }
        }
    }
}


int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++)
    {
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
}