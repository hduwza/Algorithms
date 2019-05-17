//
// Created by wza on 2019/5/17.
//
#include <iostream>

using namespace std;

void exchange(int *A, int i, int j) {
    //exchange A[i] and A[j]
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int PARTITION(int *A, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; ++j)
        if (A[j] <= A[r])
            exchange(A, ++i, j);
    exchange(A, ++i, r);
    return i;


}

void QUICK_SORT(int *A, int p, int r) {

    int q;
    if (p < r) {
        q = PARTITION(A, p, r);
        QUICK_SORT(A, p, q - 1);
        QUICK_SORT(A, q + 1, r);
    }
}

int main() {
    int nums[] = {2, 8, 7, 1, 3, 5, 6, 4};
    QUICK_SORT(nums, 0, 7);
    for (int num : nums) {
        cout << num << "    ";
    }
}
