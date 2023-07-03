#include "List.h"
#include <iostream>

void List::insertionsort(int A[], int l, int r) {
    for(int j = l+1; j <= r; j++) {
        int key = A[j];
        int i = j-1;
        while(i >= l && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void List::bubblesort(int A[], int l, int r) {
    for(int i = l; i < r; i++) {
        for(int j = r; j > i; j--) {
            if(A[j] < A[j-1]) {
                std::swap(A[j],A[j-1]);
            }
        }
    }
}
void List::mergesort(int A[], int l, int r)
{
    
}