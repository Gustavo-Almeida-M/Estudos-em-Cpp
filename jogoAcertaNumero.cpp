#include<iostream>

#include<cstdlib>

using namespace std;

int main(){

    // Using system time as a seed value
    srand(3);
    int my_rand = rand();
    int chute;
    // Printing the output

    cout << my_rand  << endl;
    while(chute != my_rand)
    {
        cout << "Digite o número para chutar:" << endl;
        cin >> chute;
        if(chute != my_rand)
        {
            cout << "Errou, tente novamente";
        }
    }
    cout << "Parabéns !! você acertou";

    return 0;

}