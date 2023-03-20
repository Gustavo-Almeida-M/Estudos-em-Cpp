#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double factor(int divisor)
{
    double fac = 0;
    if(divisor==0)
    {
        fac=1;
        cout << fac << endl;
    }
    else if(divisor!=0)
    {
        fac = 1;
        for(int i = 1; i <= divisor; i++)
        {
            fac *= i;
        }
    }
    return fac;
}
double fazEuler(int divisor)
{
    double eulerFunc = 1;
    for(int i = 1; i <= divisor; i++)
    {
        eulerFunc += 1/factor(i);
    }
    return eulerFunc;
}
int main()
{
    cout << fixed << setprecision(6);
    int divisor;
    cin >> divisor;
    
    double euler = fazEuler(divisor);
    cout << euler;
}