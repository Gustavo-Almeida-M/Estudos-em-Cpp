#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    float a = 0;
    float b = 0;
    float c = 0;
    
    cin >> a;
    cin >> b;
    cin >> c;
    
    float p = 0;
    p = (a + b + c)/2;
    float area = 0;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    cout << area;
}