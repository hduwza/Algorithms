//
// Created by wza on 2019/5/17.
//
#include <iostream>



using namespace std;

void COUNTING_SORT(int *A) {
    int B[6];
    int C[8];
    //initial
    for (int i = 0; i < 6; i++)
        B[i] = 0;
    for (int i = 0; i < 8; i++) {
        B[A[i]]++;
    }

    for (int i = 1; i < 6; i++) {
        B[i] = B[i] + B[i - 1];
    }

    for (int i = 7; i >= 0; --i) {
        C[--B[A[i]]] = A[i];
    }

    for (int i = 0; i < 8; ++i) {
        A[i] = C[i];
    }
}

int main() {
    int num[] = {2, 5, 3, 0, 2, 3, 0, 3};
    COUNTING_SORT(num);
    for (int i = 0; i < 8; ++i) {
        cout << num[i] << "     ";
    }
}