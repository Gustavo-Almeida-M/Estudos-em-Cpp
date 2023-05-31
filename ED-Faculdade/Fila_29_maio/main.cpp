#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<string> fila;

    fila.push("adriana");
    fila.push("maria");
    fila.push("juca");
    fila.push("julia");

    while(!fila.empty()) {
        cout << fila.front() << endl;
        fila.pop();
    }
}